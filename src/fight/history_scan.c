/* Scan the original 320-slot paired history ring. Classification, the
 * 30/160/240 scan limits, and signed slot wrap match the original helper.
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
static void classify(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    condition(s,R(4)==0);R(7)=R(6);
    if(R(17)&1){
        condition(s,R(5)==0);
        if(!(R(17)&1)){R(7)=R(6);R(7)+=64;}
        R(6)=READ(0x0c0a8790,4);R(5)=READ(R(7)+16,4);condition(s,(R(5)&R(6))==0);
        if(R(17)&1)R(4)=1;
    }else{
        condition(s,R(5)==0);if(R(17)&1){R(7)=R(6);R(7)+=64;}
        R(5)=READ(0x0c0a87f0,4);R(6)=READ(R(7)+16,4);condition(s,(R(6)&R(5))==0);
        if(R(17)&1)R(4)=2;
    }
    R(0)=R(4);s->pc=R(16);
}
int vf3_history_scan_c(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    push(s,ram,R(14));R(14)=R(5);push(s,ram,R(13));R(13)=R(7);
    push(s,ram,R(12));push(s,ram,R(11));R(11)=R(4);push(s,ram,R(16));
    R(15)-=4;WRITE(R(15),R(6),4);
    for(;;){
        R(4)=R(14)<<7;R(12)=READ(0x0c0a878c,4);R(6)=R(4);R(0)=59;R(6)+=R(12);
        R(4)=byte(ram,R(6)+R(0));condition(s,R(4)==0);
        if(R(17)&1){R(0)=1;goto done;}
        R(0)=R(11);condition(s,R(0)==2);
        if(!(R(17)&1)){
            R(5)=READ(R(15),4);R(4)=R(11);R(16)=0x0c0a86e8;
            classify(s,ram);R(11)=R(0);
        }
        R(0)=R(11);R(5)=word(ram,0x0c0a8784);condition(s,R(0)==2);
        if(R(17)&1){
            R(4)=0;
            do {
                R(6)=R(14)<<7;R(0)=59;R(6)+=R(12);R(6)=byte(ram,R(6)+R(0));condition(s,R(6)==0);
                if(R(17)&1)break;
                R(14)--;condition(s,(int32_t)R(14)>=0);R(13)++;if(!(R(17)&1))R(14)=R(5);
                R(3)=30;R(4)++;condition(s,(int32_t)R(4)>=(int32_t)R(3));
            }while(!(R(17)&1));
            R(4)=R(13);break;
        }
        R(14)--;condition(s,(int32_t)R(14)>=0);R(13)++;if(!(R(17)&1))R(14)=R(5);
        R(6)=word(ram,0x0c0a8786);condition(s,(int32_t)R(13)>=(int32_t)R(6));
        if(R(17)&1){R(4)=R(6);break;}
    }
    R(6)=word(ram,0x0c0a8788);condition(s,(int32_t)R(4)>=(int32_t)R(6));
    if(!(R(17)&1))for(;;){
        R(7)=R(14)<<7;R(0)=59;R(7)+=R(12);R(7)=byte(ram,R(7)+R(0));condition(s,R(7)==0);
        if(R(17)&1)break;
        R(14)--;condition(s,(int32_t)R(14)>=0);R(13)++;R(4)=R(13);
        if(!(R(17)&1))R(14)=R(5);
        condition(s,(int32_t)R(4)>(int32_t)R(6));if(R(17)&1)break;
    }
    R(0)=R(4);
done:
    R(15)+=4;R(16)=pop(s,ram);R(11)=pop(s,ram);R(12)=pop(s,ram);R(13)=pop(s,ram);R(14)=pop(s,ram);
    s->pc=R(16);return ram->oob==0;
}
