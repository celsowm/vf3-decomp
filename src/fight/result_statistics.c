/* Match result bookkeeping: paired character counts, capped statistics,
 * winning-side streaks and the remembered winner. Leaf callback 0c09d138. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <string.h>
#define R(n) s->v[(n)]
#define F(n) s->v[21+(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
static void condition(vf3_matrix_state*s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static uint32_t byte(const vf3_ram_map*ram,uint32_t a){return (uint32_t)(int32_t)(int8_t)READ(a,1);}
static void push(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t v){R(15)-=4;WRITE(R(15),v,4);}
static uint32_t pop(vf3_matrix_state*s,const vf3_ram_map*ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static int greater(uint32_t a,uint32_t b){float x,y;memcpy(&x,&a,4);memcpy(&y,&b,4);return x>y;}
static void increment(vf3_matrix_state*s,const vf3_ram_map*ram,unsigned address,unsigned one)
{vf3_matrix_load(s,ram,3,R(address));F(3)=vf3_fpu_binary(F(3),F(one),R(18),'+');vf3_matrix_store(s,ram,3,R(address));}

int vf3_result_statistics_c(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    push(s,ram,R(14));R(0)=41;for(unsigned n=13;n>=9;n--)push(s,ram,R(n));
    R(6)=READ(0x0c09d1e0,4);push(s,ram,R(19));R(0)=byte(ram,R(6)+R(0));R(4)=READ(0x0c09d1e8,4);R(0)&=255;
    condition(s,R(0)==3);R(15)-=8;if(!(R(17)&1))goto done;
    R(0)=25;R(0)=byte(ram,R(6)+R(0))&255;condition(s,R(0)==2);if(R(17)&1)goto done;
    R(0)=0x1c4;R(5)=READ(0x0c09d1ec,4);R(2)=READ(R(6)+R(0),4);R(3)=READ(R(5)+16,4);condition(s,R(2)==R(3));R(13)=(R(17)&1)?0:1;
    condition(s,R(13)==0);R(0)=97;
    if(R(17)&1){R(7)=READ(R(5)+16,4);R(14)=READ(R(5)+20,4);}
    else{R(14)=READ(R(5)+16,4);R(7)=READ(R(5)+20,4);}
    R(12)=byte(ram,R(14)+R(0));R(7)=byte(ram,R(7)+R(0));R(12)&=255;R(9)=READ(0x0c09d1f0,4);R(14)=R(12);R(7)&=255;WRITE(R(9),R(7),4);
    R(14)<<=2;R(3)=READ(0x0c09d1f4,4);R(5)=R(7);R(11)=READ(0x0c09d1f8,4);R(1)=READ(R(3),4);R(10)=999;R(0)=R(1);condition(s,R(0)==0xffffffff);R(5)<<=2;
    if(R(17)&1){R(0)=READ(R(9),4);R(2)=1;R(0)<<=2;WRITE(R(11)+R(0),R(2),4);}
    else{
        condition(s,R(1)==R(13));
        if(R(17)&1){
            R(0)=READ(R(9),4);R(0)<<=2;R(2)=READ(R(11)+R(0),4);condition(s,(int32_t)R(2)>=(int32_t)R(10));
            if(!(R(17)&1)){R(0)=READ(R(9),4);R(0)<<=2;R(2)=READ(R(11)+R(0),4);R(2)++;WRITE(R(11)+R(0),R(2),4);}
        }else{
            R(0)=R(14);R(11)=READ(R(11)+R(0),4);R(0)=READ(0x0c09d320,4);WRITE(R(15),R(0),4);R(2)=READ(R(14)+R(0),4);
            condition(s,(int32_t)R(2)>=(int32_t)R(11));WRITE(R(15)+4,R(2),4);
            if(!(R(17)&1)){R(0)=READ(R(15),4);WRITE(R(14)+R(0),R(11),4);}
            R(0)=READ(0x0c09d324,4);R(3)=0;WRITE(R(14)+R(0),R(3),4);R(3)=1;WRITE(R(5)+R(0),R(3),4);
        }
    }
    /* Pair statistics use a 13-by-13 matrix. Both participant directions are
     * counted separately, along with each character's aggregate totals. */
    R(2)=13;R(19)=R(7)*R(2);R(3)=13;R(0)=0x0c09d328;R(2)=R(19);R(19)=R(12)*R(3);R(2)+=R(12);WRITE(R(15)+4,R(2),4);
    R(12)=R(19);R(12)+=R(7);R(7)=R(2);R(7)<<=2;WRITE(R(15),R(12),4);R(2)=0x3ec;vf3_matrix_load(s,ram,4,R(0));R(2)+=R(4);R(2)+=R(7);
    vf3_matrix_load(s,ram,3,R(2));condition(s,greater(F(4),F(3)));F(5)=0x3f800000;
    if(R(17)&1){R(1)=0x3ec;R(1)+=R(4);R(1)+=R(7);increment(s,ram,1,5);}
    R(3)=0x3ec;R(12)=READ(R(15),4);R(3)+=R(4);R(12)<<=2;R(3)+=R(12);vf3_matrix_load(s,ram,3,R(3));condition(s,greater(F(4),F(3)));
    if(R(17)&1){R(2)=0x3ec;R(2)+=R(4);R(12)+=R(2);increment(s,ram,12,5);}
    R(3)=0x690;R(3)+=R(4);R(3)+=R(7);vf3_matrix_load(s,ram,3,R(3));condition(s,greater(F(4),F(3)));
    if(R(17)&1){R(2)=0x690;R(2)+=R(4);R(7)+=R(2);increment(s,ram,7,5);}
    static const unsigned participant_offsets[]={0x2e8,0x2e8,0x31c};
    static const unsigned participant_indices[]={5,14,5};
    for(unsigned n=0;n<3;n++){
        R(3)=participant_offsets[n];R(3)+=R(4);R(3)+=R(participant_indices[n]);vf3_matrix_load(s,ram,3,R(3));condition(s,greater(F(4),F(3)));
        if(R(17)&1){R(2)=participant_offsets[n];R(2)+=R(4);R(2)+=R(participant_indices[n]);increment(s,ram,2,5);}
    }
    R(3)=0xb70;R(3)+=R(4);R(3)+=R(5);vf3_matrix_load(s,ram,3,R(3));condition(s,greater(F(4),F(3)));R(0)=24;
    if(R(17)&1){R(2)=0xb70;F(2)=0x3f800000;R(2)+=R(4);R(2)+=R(14);increment(s,ram,2,2);}
    R(0)=byte(ram,R(6)+R(0))&255;condition(s,R(0)==0);
    if(R(17)&1){
        R(3)=0x350;R(3)+=R(4);R(3)+=R(5);R(2)=READ(R(3),4);condition(s,R(2)>=R(10));
        if(!(R(17)&1)){R(1)=0x350;R(1)+=R(4);R(5)+=R(1);R(3)=READ(R(5),4);R(3)++;WRITE(R(5),R(3),4);}
    }else{
        condition(s,R(0)==1);
        if(R(17)&1){R(1)=0x384;R(1)+=R(4);R(1)+=R(5);R(3)=READ(R(1),4);condition(s,R(3)>=R(10));if(!(R(17)&1)){R(1)=0x384;R(1)+=R(4);R(5)+=R(1);R(3)=READ(R(5),4);R(3)++;WRITE(R(5),R(3),4);}}
        else{condition(s,R(0)==2);if(R(17)&1){R(1)=0x3b8;R(1)+=R(4);R(1)+=R(5);R(3)=READ(R(1),4);condition(s,R(3)>=R(10));if(!(R(17)&1)){R(1)=0x3b8;R(1)+=R(4);R(5)+=R(1);R(3)=READ(R(5),4);R(3)++;WRITE(R(5),R(3),4);}}}
    }
    R(2)=READ(0x0c09d3f0,4);WRITE(R(2),R(13),4);
done:
    R(15)+=8;R(19)=pop(s,ram);for(unsigned n=9;n<=14;n++)R(n)=pop(s,ram);s->pc=R(16);return ram->oob==0;
}
