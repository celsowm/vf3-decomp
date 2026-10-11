/* Record paired actor state into one of the original 320 history slots.
 * Field packing preserves the signed word/byte loads and staging clears.
 */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
static void condition(vf3_matrix_state*s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static uint32_t word(const vf3_ram_map*ram,uint32_t a){return (uint32_t)(int32_t)(int16_t)READ(a,2);}
static uint32_t byte(const vf3_ram_map*ram,uint32_t a){return (uint32_t)(int32_t)(int8_t)READ(a,1);}
static void push(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t v){R(15)-=4;WRITE(R(15),v,4);}
static uint32_t pop(vf3_matrix_state*s,const vf3_ram_map*ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static void pack_actor(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    R(0)=16;R(3)=READ(R(5),4);R(15)-=44;R(7)=R(4);WRITE(R(15),R(3),4);R(1)=R(15);
    vf3_matrix_load(s,ram,4,R(5)+R(0));R(0)=20;vf3_matrix_load(s,ram,5,R(5)+R(0));
    R(0)=24;vf3_matrix_load(s,ram,6,R(5)+R(0));R(0)=72;R(3)=READ(R(5)+R(0),4);
    R(1)+=36;R(4)=R(6);WRITE(R(15)+40,R(3),4);R(0)=word(ram,R(5)+30);WRITE(R(1),R(0),2);
    R(0)=60;R(3)=word(ram,R(5)+R(0));R(0)=32;WRITE(R(15)+R(0),R(3),2);
    R(0)=62;R(0)=word(ram,R(5)+R(0));WRITE(R(15)+28,R(0),2);
    R(0)=word(ram,0x0c0a8558);R(3)=READ(R(5)+R(0),4);R(0)=70;WRITE(R(15)+20,R(3),4);
    R(0)=word(ram,R(5)+R(0));WRITE(R(15)+24,R(0),2);R(0)=word(ram,0x0c0a855a);R(6)=READ(R(5)+R(0),4);
    R(0)=word(ram,0x0c0a855c);R(3)=READ(R(5)+R(0),4);WRITE(R(15)+16,R(3),4);
    R(0)=word(ram,0x0c0a855e);R(0)=byte(ram,R(5)+R(0));WRITE(R(15)+12,R(0),1);
    R(0)=word(ram,0x0c0a8560);R(0)=byte(ram,R(5)+R(0));WRITE(R(15)+8,R(0),1);
    R(3)=READ(0x0c0a8564,4);R(0)=byte(ram,R(3));WRITE(R(15)+4,R(0),1);
    R(0)=4;R(2)=READ(R(15),4);WRITE(R(4),R(2),4);vf3_matrix_store(s,ram,4,R(4)+R(0));
    R(0)=8;vf3_matrix_store(s,ram,5,R(4)+R(0));R(0)=12;vf3_matrix_store(s,ram,6,R(4)+R(0));
    R(0)=36;R(2)=READ(R(15)+40,4);WRITE(R(4)+16,R(2),4);R(1)=word(ram,R(15)+R(0));
    R(0)=32;WRITE(R(4)+R(0),R(1),2);R(0)=32;R(2)=word(ram,R(15)+R(0));R(0)=34;WRITE(R(4)+R(0),R(2),2);
    R(0)=word(ram,R(15)+28);R(1)=R(4)+36;WRITE(R(1),R(0),2);R(2)=R(4)+42;
    R(0)=word(ram,R(15)+24);WRITE(R(2),R(0),2);R(1)=READ(R(15)+20,4);WRITE(R(4)+44,R(1),4);
    R(1)=56;R(2)=READ(R(15)+16,4);R(1)+=R(4);WRITE(R(4)+48,R(2),4);R(2)=57;
    R(0)=byte(ram,R(15)+12);R(2)+=R(4);WRITE(R(1),R(0),1);R(1)=58;
    R(0)=byte(ram,R(15)+8);R(1)+=R(4);WRITE(R(2),R(0),1);R(0)=byte(ram,R(15)+4);WRITE(R(1),R(0),1);
    R(0)=R(6);condition(s,R(0)==2);
    if(R(17)&1){
        R(7)=READ(R(7)+16,4)-1;condition(s,(int32_t)R(7)>=0);if(!(R(17)&1))R(7)=word(ram,0x0c0a8562);
        R(1)=READ(0x0c0a856c,4);R(7)<<=4;R(3)=READ(0x0c0a8568,4);R(2)=READ(R(1),4);R(7)<<=3;
        condition(s,R(2)==R(5));WRITE(R(15),R(2),4);R(7)+=R(3);if(!(R(17)&1))R(7)+=64;
        R(5)=R(7);R(5)=READ(R(5)+28,4);condition(s,R(5)==0);if(R(17)&1)R(6)=1;
    }
    WRITE(R(4)+28,R(6),4);R(0)=59;R(5)=READ(0x0c0a8570,4);R(2)=1;R(7)=R(5)+48;
    R(6)=READ(R(7),4);R(7)=READ(R(7)+4,4);WRITE(R(4)+20,R(6),4);R(6)=0;
    WRITE(R(4)+24,R(7),4);WRITE(R(5)+48,R(6),4);WRITE(R(5)+52,R(6),4);
    WRITE(R(4)+R(0),R(2),1);R(15)+=44;s->pc=R(16);
}
int vf3_history_record_c(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    push(s,ram,R(14));push(s,ram,R(13));push(s,ram,R(12));push(s,ram,R(11));push(s,ram,R(10));
    R(1)=READ(0x0c0a8444,4);push(s,ram,R(16));R(2)=READ(R(1),4);R(3)=READ(0x0c0a8440,4);
    condition(s,(R(2)&R(3))==0);R(11)=R(4);
    if(R(17)&1){
        R(10)=R(11);R(14)=READ(R(10)+16,4);R(2)=READ(0x0c0a8448,4);R(13)=R(14)<<4;
        R(3)=READ(0x0c0a8438,4);R(13)<<=2;R(12)=READ(R(2),4);R(13)<<=1;R(13)+=R(3);
        R(5)=R(12);R(6)=R(13);R(4)=R(11);R(16)=0x0c0a83f8;pack_actor(s,ram);
        R(0)=40;R(3)=READ(0x0c0a844c,4);vf3_matrix_load(s,ram,3,R(12)+R(0));R(13)+=64;R(6)=R(13);
        vf3_matrix_store(s,ram,3,R(3));R(2)=READ(0x0c0a8450,4);R(5)=READ(R(2),4);
        R(4)=R(10);R(16)=0x0c0a840c;pack_actor(s,ram);R(2)=word(ram,0x0c0a8430);R(0)=40;R(14)++;
        vf3_matrix_load(s,ram,3,R(12)+R(0));R(3)=READ(0x0c0a8454,4);condition(s,R(14)>R(2));
        vf3_matrix_store(s,ram,3,R(3));if(R(17)&1)R(14)=0;WRITE(R(10)+16,R(14),4);
    }
    R(16)=pop(s,ram);R(10)=pop(s,ram);R(11)=pop(s,ram);R(12)=pop(s,ram);R(13)=pop(s,ram);R(14)=pop(s,ram);
    s->pc=R(16);return ram->oob==0;
}
