/* Pack paired fight-history records into the selected round's replay ring.
 * The ring has 320 entries; the signed byte count mirrors the original.
 */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
static void condition(vf3_matrix_state*s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static uint32_t byte(const vf3_ram_map*ram,uint32_t a){return (uint32_t)(int32_t)(int8_t)READ(a,1);}
static uint32_t word(const vf3_ram_map*ram,uint32_t a){return (uint32_t)(int32_t)(int16_t)READ(a,2);}
static void push(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t v){R(15)-=4;WRITE(R(15),v,4);}
static uint32_t pop(vf3_matrix_state*s,const vf3_ram_map*ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static void copy_record(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    R(0)=4;R(7)=READ(R(4)+16,4);vf3_matrix_load(s,ram,4,R(4)+R(0));
    R(0)=8;vf3_matrix_load(s,ram,6,R(4)+R(0));R(0)=12;vf3_matrix_load(s,ram,5,R(4)+R(0));
    R(0)=32;R(0)=word(ram,R(4)+R(0));R(15)-=16;R(6)=READ(R(4),4);WRITE(R(15)+12,R(0),2);
    R(0)=34;R(0)=word(ram,R(4)+R(0));WRITE(R(15)+8,R(0),2);
    R(0)=36;R(0)=word(ram,R(4)+R(0));WRITE(R(15)+4,R(0),2);
    R(0)=59;R(3)=byte(ram,R(4)+R(0));R(0)=4;WRITE(R(15),R(3),1);R(4)=READ(R(4)+44,4);
    vf3_matrix_store(s,ram,4,R(5)+R(0));R(0)=8;vf3_matrix_store(s,ram,6,R(5)+R(0));
    R(0)=12;vf3_matrix_store(s,ram,5,R(5)+R(0));WRITE(R(5),R(6),4);WRITE(R(5)+16,R(7),4);
    R(0)=word(ram,R(15)+12);WRITE(R(5)+20,R(0),2);R(0)=word(ram,R(15)+8);WRITE(R(5)+22,R(0),2);
    R(0)=word(ram,R(15)+4);WRITE(R(5)+24,R(0),2);R(0)=26;R(3)=byte(ram,R(15));
    WRITE(R(5)+R(0),R(3),1);WRITE(R(5)+28,R(4),4);R(15)+=16;s->pc=R(16);
}
int vf3_replay_history_c(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    push(s,ram,R(14));R(0)=80;push(s,ram,R(13));push(s,ram,R(12));push(s,ram,R(11));push(s,ram,R(10));
    push(s,ram,R(16));push(s,ram,R(19));R(15)-=8;WRITE(R(15)+4,R(4),4);WRITE(R(15),R(5),4);
    R(5)=READ(0x0c0a88f4,4);R(10)=word(ram,0x0c0a88e6);R(4)=READ(R(5)+R(0),4);
    R(14)=READ(R(4)+16,4)-1;condition(s,(int32_t)R(14)>=0);if(!(R(17)&1))R(14)=R(10);
    R(0)=word(ram,0x0c0a88e8);R(13)=READ(0x0c0a88f8,4);WRITE(R(13)+R(0),R(14),4);
    R(0)=word(ram,0x0c0a88ea);R(5)=READ(R(5)+16,4);R(4)=READ(R(13)+R(0),4);
    condition(s,R(4)==R(5));R(6)=0;if(!(R(17)&1))R(6)=1;
    R(7)=0;R(5)=R(14);R(4)=R(7);R(16)=0x0c0a883e;
    if(!vf3_matrix_family(0x0c0a86ac,s,ram)||s->pc!=R(16))return 0;
    R(4)=R(0);
    do {R(14)--;condition(s,(int32_t)R(14)>=0);if(!(R(17)&1))R(14)=R(10);
        R(4)--;condition(s,R(4)==0);
    }while(!(R(17)&1));
    R(0)=word(ram,0x0c0a88ec);R(1)=96;WRITE(R(13)+R(0),R(14),4);
    R(0)=43;R(4)=byte(ram,R(13)+R(0));R(3)=READ(0x0c0a88fc,4);R(0)=READ(R(15)+4,4);
    R(4)--;R(6)=R(4);R(7)=byte(ram,R(3));R(3)=R(4);R(6)<<=1;
    R(0)=byte(ram,R(1)+R(0));R(6)+=R(3);R(5)=word(ram,0x0c0a88ee);
    R(4)=(uint32_t)(int32_t)(int8_t)R(4);WRITE(R(15)+4,R(0),1);R(0)=R(1);R(2)=READ(R(15),4);
    R(5)+=R(13);R(6)=(uint32_t)(int32_t)(int8_t)R(6);R(2)=byte(ram,R(2)+R(0));R(5)+=R(6);
    WRITE(R(15),R(2),1);WRITE(R(5),R(7),1);R(0)=byte(ram,R(15)+4);WRITE(R(5)+1,R(0),1);
    R(0)=byte(ram,R(15));WRITE(R(5)+2,R(0),1);R(3)=word(ram,0x0c0a88f0);
    R(19)=(uint32_t)((int32_t)(int16_t)R(3)*(int32_t)(int16_t)R(4));R(4)=R(19);
    R(0)=word(ram,0x0c0a88ec);R(14)=READ(0x0c0a8900,4);R(12)=READ(R(13)+R(0),4);R(14)+=R(4);
    do {
        R(4)=R(12)<<7;R(11)=READ(0x0c0a8904,4);R(5)=R(14);R(11)+=R(4);
        R(4)=R(11);R(16)=0x0c0a88a8;copy_record(s,ram);R(14)+=32;R(5)=R(14);R(11)+=64;
        R(4)=R(11);R(16)=0x0c0a88b2;copy_record(s,ram);R(12)++;condition(s,R(12)>R(10));R(14)+=32;
        if(R(17)&1)R(12)=0;
        R(0)=word(ram,0x0c0a88e8);R(4)=READ(R(13)+R(0),4);R(0)+=4;R(3)=byte(ram,R(13)+R(0))+1;
        WRITE(R(13)+R(0),R(3),1);R(3)=word(ram,0x0c0a88f2);R(2)=byte(ram,R(13)+R(0));
        condition(s,(int32_t)R(2)>=(int32_t)R(3));if(R(17)&1)break;
        condition(s,R(4)==R(12));
    }while(!(R(17)&1));
    R(15)+=8;R(19)=pop(s,ram);R(16)=pop(s,ram);R(10)=pop(s,ram);R(11)=pop(s,ram);
    R(12)=pop(s,ram);R(13)=pop(s,ram);R(14)=pop(s,ram);s->pc=R(16);return ram->oob==0;
}
