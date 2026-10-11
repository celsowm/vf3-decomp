/* Actor geometry at 0x8c0ca8c0: solve two line/circle intersections, publish
 * distances and reflected angles. Guest scratch state retains the SH-4 ABI.
 * Frozen owner 0x8c0ca8da excludes the integer/FR save prefix. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <string.h>
#define R(n) s->v[(n)]
#define F(n) s->v[21+(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t value)
{ R(15)-=4;WRITE(R(15),value,4); }
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram)
{ uint32_t value=READ(R(15),4);R(15)+=4;return value; }
static void condition(vf3_matrix_state *s,int value)
{ R(17)=(R(17)&~1u)|(value!=0); }
static float value(uint32_t bits)
{ float result;memcpy(&result,&bits,4);return result; }
static uint32_t word(uint32_t bits)
{ return (uint32_t)(int32_t)(int16_t)bits; }
static void arithmetic(vf3_matrix_state *s,unsigned to,unsigned from,char operation)
{ F(to)=vf3_fpu_binary(F(to),F(from),R(18),operation); }
static void mac(vf3_matrix_state *s,unsigned to,unsigned from)
{ F(to)=vf3_fpu_mac(F(0),F(from),F(to),R(18)); }
static int call(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t target,uint32_t return_pc)
{ R(16)=return_pc;return vf3_matrix_family(target,s,ram) && s->pc==return_pc; }

/* The quadratic solver overwrites the four stack arguments with (x,y) pairs.
 * Discriminants below the original epsilon are clamped before square root. */
int vf3_geometry_intersections_c(uint32_t entry,vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t alias)
{
    if(!vf3_fpu_supported(R(18)) || (R(18)&0x100000u))return 0;
    if(entry==0x0c0ca838u){
        push(s,ram,F(15));R(0)=alias+0x0ca90c;
        F(5)=READ(R(4),4);F(4)=READ(R(5),4);
        F(6)=F(5);arithmetic(s,6,5,'*');F(7)=F(4);arithmetic(s,7,4,'*');
        F(3)=0x3f800000;F(8)=READ(R(6),4);
        F(15)=F(6);arithmetic(s,15,3,'+');F(9)=F(6);arithmetic(s,9,7,'*');
        arithmetic(s,7,8,'-');F(1)=READ(R(0),4);
        F(6)=F(15);arithmetic(s,6,7,'*');F(2)=F(6);F(6)=F(9);arithmetic(s,6,2,'-');
        condition(s,value(F(1))>value(F(6)));
        F(8)=(R(17)&1u)?0:vf3_fpu_sqrt(F(6),R(18));
        F(6)=F(5);arithmetic(s,6,4,'*');F(9)=F(4);F(0)=F(5);
        F(7)=F(6)^0x80000000u;F(6)=F(8);arithmetic(s,6,7,'+');
        arithmetic(s,7,8,'-');arithmetic(s,6,15,'/');arithmetic(s,7,15,'/');
        mac(s,9,6);WRITE(R(4),F(6),4);mac(s,4,7);WRITE(R(5),F(9),4);
        WRITE(R(6),F(7),4);WRITE(R(7),F(4),4);F(15)=pop(s,ram);
    }else{
        /* Near-vertical line: its x coordinate is fixed. */
        F(0)=READ(R(4),4);R(0)=alias+0x0ca90c;
        F(3)=F(0);arithmetic(s,3,0,'*');WRITE(R(4),F(3),4);
        F(2)=READ(R(6),4);arithmetic(s,2,3,'-');WRITE(R(4),F(2),4);
        F(4)=F(2);F(2)=READ(R(0),4);condition(s,value(F(2))>value(F(4)));
        F(3)=(R(17)&1u)?0:vf3_fpu_sqrt(F(4),R(18));WRITE(R(5),F(3),4);
        F(3)^=0x80000000u;WRITE(R(7),F(3),4);WRITE(R(4),F(0),4);WRITE(R(6),F(0),4);
    }
    s->pc=R(16);return ram->oob==0;
}

int vf3_geometry_angles_c(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t alias)
{
    if(!vf3_fpu_supported(R(18)) || (R(18)&0x100000u))return 0;
    push(s,ram,R(14));push(s,ram,R(13));R(13)=R(4);
    push(s,ram,R(12));push(s,ram,R(11));R(11)=2;
    push(s,ram,R(10));push(s,ram,R(9));
    for(int fr=15;fr>=12;--fr)push(s,ram,F(fr));
    R(0)=0x1394;push(s,ram,R(16));R(10)=word(READ(R(13)+R(0),2));
    R(0)=0x430;R(15)-=28;F(15)=READ(R(13)+R(0),4);
    R(0)+=8;F(12)=READ(R(13)+R(0),4);R(0)=alias+0x0ca90c;F(3)=READ(R(0),4);
    R(0)=16;R(9)=0u-R(10);F(4)=F(12);F(12)^=0x80000000u;WRITE(R(15)+R(0),F(3),4);
    R(0)=alias+0x0ca910;F(3)=READ(R(0),4);R(0)=20;WRITE(R(15)+R(0),F(3),4);
    R(0)=alias+0x0ca914;F(3)=READ(R(0),4);R(0)=24;WRITE(R(15)+R(0),F(3),4);
    for(;;){
        R(3)=0;condition(s,R(11)>R(3));if(!(R(17)&1u))break;
        R(12)=0x0c03a6e0;R(14)=word(R(9));R(4)=R(14);
        if(!call(s,ram,R(12),alias+0x0ca920))return 0;
        WRITE(R(15),F(0),4);R(12)=0x0c03a140;R(4)=R(14);
        if(!call(s,ram,R(12),alias+0x0ca928))return 0;
        R(0)=4;WRITE(R(15)+R(0),F(0),4);
        R(0)=20;F(3)=READ(R(15),4);F(4)=F(15);arithmetic(s,4,3,'+');F(3)=F(0);
        F(2)=READ(R(15)+R(0),4);R(0)=8;F(5)=F(12);arithmetic(s,5,3,'+');
        F(3)=F(4);F(4)=F(15);arithmetic(s,4,3,'-');F(3)=F(5);F(5)=F(12);arithmetic(s,5,3,'-');
        WRITE(R(15)+R(0),F(2),4);R(0)=16;F(3)=READ(R(15)+R(0),4);
        condition(s,value(F(3))>value(F(4)));
        if(R(17)&1u){R(0)=24;F(3)=READ(R(15)+R(0),4);condition(s,value(F(4))>value(F(3)));}
        if(R(17)&1u){
            R(6)=R(15);R(5)=R(15);R(7)=R(15);WRITE(R(15),F(15),4);
            R(5)+=4;R(7)+=12;R(6)+=8;R(4)=R(15);
            if(!call(s,ram,0x0c0ca894,alias+0x0ca970))return 0;
        }else{
            arithmetic(s,5,4,'/');R(7)=R(15);R(6)=R(15);R(5)=R(15);R(0)=4;
            R(5)+=4;R(6)+=8;R(7)+=12;WRITE(R(15),F(5),4);
            F(4)=F(5);arithmetic(s,4,15,'*');F(3)=F(12);arithmetic(s,3,4,'-');
            WRITE(R(15)+R(0),F(3),4);R(4)=R(15);
            if(!call(s,ram,0x0c0ca838,alias+0x0ca994))return 0;
        }
        /* Measure each intersection's distance from the actor's center. */
        F(4)=READ(R(15),4);R(0)=4;F(6)=F(15);arithmetic(s,6,4,'-');
        F(5)=READ(R(15)+R(0),4);F(7)=F(12);R(0)=8;arithmetic(s,7,5,'-');
        F(13)=READ(R(15)+R(0),4);R(0)=12;F(3)=F(6);arithmetic(s,3,6,'*');
        F(14)=READ(R(15)+R(0),4);R(0)=alias+0x0caa40;F(0)=F(7);mac(s,3,7);
        WRITE(R(15),F(3),4);F(2)=READ(R(15),4);F(3)=READ(R(0),4);
        condition(s,value(F(3))>value(F(2)));F(7)=F(15);
        if(R(17)&1u)F(6)=0;
        else{F(2)=vf3_fpu_sqrt(F(2),R(18));F(6)=F(2);}
        arithmetic(s,7,13,'-');F(8)=F(12);arithmetic(s,8,14,'-');R(0)=alias+0x0caa40;
        F(3)=F(7);arithmetic(s,3,7,'*');F(0)=F(8);mac(s,3,8);
        WRITE(R(15),F(3),4);F(2)=READ(R(15),4);F(3)=READ(R(0),4);
        condition(s,value(F(3))>value(F(2)));
        if(R(17)&1u)F(7)=0;
        else{F(2)=vf3_fpu_sqrt(F(2),R(18));F(7)=F(2);}
        R(14)=0x8000;R(3)=R(10);condition(s,(R(3)&R(14))==0);
        if(R(17)&1u){
            F(8)=F(6);F(6)=F(7);F(7)=F(8);F(8)=F(4);F(4)=F(13);F(13)=F(8);
            F(8)=F(5);F(5)=F(14);F(14)=F(8);
        }
        R(0)=R(11);R(12)=0x0c069624;condition(s,R(0)==2);
        if(R(17)&1u){
            R(0)=0x140c;WRITE(R(13)+R(0),F(6),4);R(0)+=4;WRITE(R(13)+R(0),F(7),4);
            if(!call(s,ram,R(12),alias+0x0caa16))return 0;
            R(4)=word(R(0));R(0)=0x2074;R(4)=0u-R(4);R(4)^=R(14);WRITE(R(13)+R(0),R(4),2);
            F(5)=F(14);F(4)=F(13);
            if(!call(s,ram,R(12),alias+0x0caa26))return 0;
            R(4)=word(R(0));R(0)=0x2076;R(4)=0u-R(4);R(4)^=R(14);
        }else{
            R(0)=0x1568;WRITE(R(13)+R(0),F(6),4);R(0)-=4;WRITE(R(13)+R(0),F(7),4);
            if(!call(s,ram,R(12),alias+0x0caa56))return 0;
            R(4)=word(R(0));R(0)=0x207a;R(4)=0u-R(4);R(4)^=R(14);WRITE(R(13)+R(0),R(4),2);
            F(5)=F(14);F(4)=F(13);
            if(!call(s,ram,R(12),alias+0x0caa66))return 0;
            R(4)=word(R(0));R(0)=0x2078;R(4)=0u-R(4);R(4)^=R(14);
        }
        WRITE(R(13)+R(0),R(4),2);--R(11);R(4)=0x4000;R(10)+=R(4);R(9)+=R(4);
    }
    R(15)+=28;R(16)=pop(s,ram);for(int fr=12;fr<=15;++fr)F(fr)=pop(s,ram);
    R(9)=pop(s,ram);R(10)=pop(s,ram);R(11)=pop(s,ram);R(12)=pop(s,ram);R(13)=pop(s,ram);R(14)=pop(s,ram);
    s->pc=R(16);return ram->oob==0;
}
