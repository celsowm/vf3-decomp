/* Insert a scene key into eighteen parallel frame/key/identifier arrays.
 * Original uncached callable 0x0c09fefe, frozen owner 0x8c09ff12. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
static void push(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t v){R(15)-=4;WRITE(R(15),v,4);}
static uint32_t pop(vf3_matrix_state*s,const vf3_ram_map*ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static uint32_t word(const vf3_ram_map*ram,uint32_t a){return (uint32_t)(int32_t)(int16_t)READ(a,2);}
static void condition(vf3_matrix_state*s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static int invoke(vf3_matrix_state*s,const vf3_ram_map*ram,unsigned reg,uint32_t ret)
{R(16)=ret;return vf3_matrix_family(R(reg),s,ram)&&s->pc==R(16);}
int vf3_scene_insert_c(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    push(s,ram,R(14));push(s,ram,R(13));push(s,ram,R(12));R(12)=0;
    for(unsigned i=11;i>=8;i--)push(s,ram,R(i));
    R(0)=word(ram,0x0c09ff82);R(14)=READ(0x0c09ffa4,4);push(s,ram,R(16));
    R(13)=READ(0x0c09ff88,4);WRITE(R(14)+R(0),R(12),1);R(0)=32;R(4)=word(ram,0x0c09ff84);
    R(15)-=16;R(4)+=R(14);for(unsigned k=0;k<4;k++)WRITE(R(4)+3-k,R(0),1);
    R(0)+=112;WRITE(R(14)+R(0),R(12),1);R(0)++;WRITE(R(14)+R(0),R(12),1);
    R(0)-=8;WRITE(R(14)+R(0),R(12),1);R(0)++;WRITE(R(14)+R(0),R(12),1);R(0)-=6;
    R(3)=READ(R(14)+R(0),4);R(11)=READ(R(14)+48,4);R(10)=R(12);WRITE(R(15),R(3),4);
    /* Find the first key following the candidate, using signed comparisons. */
    for(;;){
        if(!s->budget--)return 0;
        R(4)=R(10);R(3)=R(13);R(4)<<=2;R(8)=READ(0x0c09ffa8,4);R(3)+=72;
        WRITE(R(15)+4,R(4),4);R(4)+=R(3);if(!invoke(s,ram,8,0x0c09ff52))return 0;
        R(4)=R(0);condition(s,(int32_t)R(11)>=(int32_t)R(4));
        if(!(R(17)&1))break;
        condition(s,(int32_t)R(11)>(int32_t)R(4));
        if(!(R(17)&1)){
            R(4)=word(ram,0x0c09ff80);R(3)=READ(R(15)+4,4);R(4)+=R(13);R(4)+=R(3);
            if(!invoke(s,ram,8,0x0c09ff66))return 0;
            R(3)=READ(R(15),4);R(4)=R(0);condition(s,(int32_t)R(3)>(int32_t)R(4));
            if(R(17)&1)break;
        }
        R(3)=18;R(10)++;condition(s,(int32_t)R(10)>=(int32_t)R(3));
        if(R(17)&1){R(0)=word(ram,0x0c09ff82);R(2)=2;WRITE(R(14)+R(0),R(2),1);goto done;}
    }
    R(0)=word(ram,0x0c0a00f4);R(4)=R(10);R(11)=17;WRITE(R(14)+R(0),R(4),1);R(9)=READ(0x0c0a0104,4);
    condition(s,(int32_t)R(10)>=(int32_t)R(11));R(4)=R(11);
    /* Move the retained suffix backwards without overwriting its sources. */
    while(!(R(17)&1)){
        if(!s->budget--)return 0;
        R(4)--;WRITE(R(15),R(4),4);R(4)<<=2;WRITE(R(15)+8,R(4),4);R(3)=word(ram,0x0c0a00f6)+R(13);R(4)+=R(3);
        if(!invoke(s,ram,8,0x0c09ffcc))return 0;
        R(4)=R(11)<<2;R(5)=R(0);WRITE(R(15)+4,R(4),4);R(3)=word(ram,0x0c0a00f6)+R(13);R(4)+=R(3);
        if(!invoke(s,ram,9,0x0c09ffdc))return 0;
        R(4)=R(13)+72;R(3)=READ(R(15)+8,4);R(4)+=R(3);if(!invoke(s,ram,8,0x0c09ffe6))return 0;
        R(4)=R(13)+72;R(3)=READ(R(15)+4,4);R(5)=R(0);R(4)+=R(3);if(!invoke(s,ram,9,0x0c09fff2))return 0;
        R(4)=READ(R(15),4)<<2;R(3)=R(13);R(4)+=R(3);if(!invoke(s,ram,8,0x0c09fffc))return 0;
        R(4)=R(11)<<2;R(3)=R(13);R(5)=R(0);R(4)+=R(3);if(!invoke(s,ram,9,0x0c0a0008))return 0;
        R(4)=word(ram,0x0c0a00f8)+R(13);R(3)=READ(R(15),4);R(4)+=R(3);R(3)=READ(0x0c0a0108,4);
        if(!invoke(s,ram,3,0x0c0a0016))return 0;
        R(0)&=255;WRITE(R(15),R(0),4);R(5)=R(0);R(4)=word(ram,0x0c0a00f8)+R(13);R(3)=READ(0x0c0a010c,4);R(4)+=R(11);
        if(!invoke(s,ram,3,0x0c0a0026))return 0;
        R(11)--;R(9)=READ(0x0c0a0104,4);condition(s,(int32_t)R(10)>=(int32_t)R(11));R(4)=R(11);
    }
    R(0)=41;R(5)=READ(0x0c0a0110,4);R(0)=READ(R(14)+R(0),1);condition(s,R(0)==1);
    R(4)=READ(R(5)+((R(17)&1)?16:20),4);R(6)=word(ram,0x0c0a00fa)+R(14);R(3)=READ(R(14)+48,4);
    R(5)=(uint32_t)(int32_t)(int8_t)READ(R(6),1);R(0)=(uint32_t)(int32_t)(int8_t)READ(R(6)+1,1);
    R(5)<<=24;R(0)<<=16;R(5)+=R(0);R(0)=(uint32_t)(int32_t)(int8_t)READ(R(6)+2,1);R(0)<<=8;R(5)+=R(0);
    R(0)=(uint32_t)(int32_t)(int8_t)READ(R(6)+3,1);WRITE(R(15),R(3),4);R(5)+=R(0);
    R(0)=word(ram,0x0c0a00fc);R(2)=READ(R(14)+R(0),4);R(0)=97;WRITE(R(15)+4,R(2),4);
    R(3)=READ(R(4)+R(0),1);WRITE(R(15)+12,R(3),4);R(3)=R(13);R(0)=word(ram,0x0c0a00f4);
    R(11)=(uint32_t)(int32_t)(int8_t)READ(R(14)+R(0),1);R(4)=R(11)<<2;R(4)+=R(3);if(!invoke(s,ram,9,0x0c0a0076))return 0;
    R(4)=R(11)<<2;R(3)=R(13)+72;R(5)=READ(R(15),4);WRITE(R(15)+8,R(4),4);R(4)+=R(3);
    if(!invoke(s,ram,9,0x0c0a0086))return 0;
    R(4)=word(ram,0x0c0a00f6)+R(13);R(3)=READ(R(15)+8,4);R(5)=READ(R(15)+4,4);R(4)+=R(3);if(!invoke(s,ram,9,0x0c0a0092))return 0;
    R(4)=word(ram,0x0c0a00f8)+R(13);R(3)=READ(0x0c0a010c,4);R(5)=READ(R(15)+12,4);R(4)+=R(11);
    if(!invoke(s,ram,3,0x0c0a009e))return 0;
    R(0)=word(ram,0x0c0a00fe);WRITE(R(14)+R(0),R(12),1);
done:
    R(15)+=16;R(16)=pop(s,ram);for(unsigned i=8;i<=13;i++)R(i)=pop(s,ram);
    s->pc=R(16);R(14)=pop(s,ram);return ram->oob==0;
}
