/* Round contact scoring. Callable 0x0c0a7be2, inventory owner 0x8c0a7bec.
 * Preserve the guest's scratch registers and stack stores as well as the score.
 */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
static void push(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t v){R(15)-=4;WRITE(R(15),v,4);}
static uint32_t pop(vf3_matrix_state*s,const vf3_ram_map*ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static uint32_t word(const vf3_ram_map*ram,uint32_t a){return (uint32_t)(int32_t)(int16_t)READ(a,2);}
static uint32_t byte(const vf3_ram_map*ram,uint32_t a){return (uint32_t)(int32_t)(int8_t)READ(a,1);}
static void condition(vf3_matrix_state*s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static void half(vf3_matrix_state*s,unsigned n){condition(s,R(n)&1);R(n)=(uint32_t)((int32_t)R(n)>>1);}
static int divide(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t ret)
{R(16)=ret;return vf3_matrix_family(R(2),s,ram)&&s->pc==R(16);}
int vf3_round_score_c(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    for(unsigned i=14;i>=10;i--)push(s,ram,R(i));
    push(s,ram,R(16));
    R(14)=READ(0x0c0a7c0c,4);R(0)=word(ram,0x0c0a7c08);push(s,ram,R(19));
    R(0)=byte(ram,R(14)+R(0));R(12)=READ(0x0c0a7c14,4);condition(s,R(0)==1);R(15)-=8;R(11)=0;
    if(R(17)&1){R(2)=READ(0x0c0a7c18,4);R(13)=READ(R(2),4);}
    else {R(1)=READ(0x0c0a7d30,4);R(13)=READ(R(1),4);}
    condition(s,R(13)==R(4));if(!(R(17)&1))goto done;
    R(13)=READ(R(14)+8,4);R(3)=8;condition(s,(R(3)&R(13))==0);if(R(17)&1)goto done;
    R(2)=READ(0x0c0a7d34,4);condition(s,(R(2)&R(13))==0);if(!(R(17)&1) )goto done;
    R(3)=word(ram,0x0c0a7d20);condition(s,(R(3)&R(13))==0);if(!(R(17)&1))goto done;
    R(2)=READ(0x0c0a7d38,4);condition(s,(R(2)&R(13))==0);if(!(R(17)&1))goto done;
    R(3)=READ(0x0c0a7d3c,4);condition(s,(R(3)&R(13))==0);if(!(R(17)&1))goto done;
    R(2)=READ(R(12),4);R(1)=R(2);WRITE(R(15),R(2),4);R(3)=READ(0x0c0a7d40,4);
    condition(s,(R(1)&R(3))==0);if(R(17)&1)goto done;
    R(0)=41;R(0)=READ(R(14)+R(0),1);condition(s,R(0)==3);if(R(17)&1)goto clear_score;
    R(3)=READ(0x0c0a7d44,4);R(12)=READ(R(12)+4,4);R(0)=word(ram,0x0c0a7d22);
    condition(s,(R(12)&R(3))==0);R(13)=word(ram,R(14)+R(0));if(!(R(17)&1))goto round_bonus;
    /* Damage is normalized against the actor's capped 181-point scale. */
    R(2)=READ(0x0c0a7d48,4);condition(s,(R(2)&R(12))==0);
    if(R(17)&1){R(3)=READ(0x0c0a7d4c,4);condition(s,(R(3)&R(12))==0);if(R(17)&1)goto done;}
    R(3)=READ(0x0c0a7d50,4);R(12)=word(ram,0x0c0a7d24);condition(s,(R(6)&R(3))==0);
    if(!(R(17)&1)){
        R(0)=word(ram,0x0c0a7d26);R(6)=word(ram,R(5)+R(0));WRITE(R(5)+R(0),R(11),2);
        R(0)=word(ram,0x0c0a7d28);R(10)=READ(R(5)+R(0),1);R(0)=word(ram,0x0c0a7d2a);R(10)+=3;
        R(19)=R(6)*R(10);R(10)=word(ram,R(4)+R(0))+1;R(6)=R(19);half(s,6);half(s,6);
        condition(s,(int32_t)R(10)>=(int32_t)R(12));R(19)=R(6)*R(12);R(6)=R(19);if(R(17)&1)R(10)=R(12);
        R(2)=READ(0x0c0a7d54,4);R(1)=R(6);R(0)=R(10);if(!divide(s,ram,0x0c0a7ccc))return 0;
        R(6)=R(0)+1;R(13)+=R(6);R(6)=(uint32_t)(int32_t)(int8_t)R(7);R(6)<<=2;
        R(0)=60;R(3)=READ(R(4)+R(0),2);WRITE(R(15),R(3),4);R(2)=READ(0x0c0a7d58,4);R(6)+=R(2);
        R(1)=word(ram,R(6));condition(s,R(3)==R(1));if(R(17)&1){R(0)=word(ram,R(6)+2);R(13)+=R(0);
            R(0)=word(ram,0x0c0a7d2c);R(3)=word(ram,R(14)+R(0))+1;WRITE(R(14)+R(0),R(3),2);}
    }
    R(0)=word(ram,0x0c0a7d26);R(6)=word(ram,R(5)+R(0));condition(s,R(6)==0);
    if(!(R(17)&1)){
        R(0)=word(ram,0x0c0a7d2a);R(19)=R(6)*R(12);R(4)=word(ram,R(4)+R(0))+1;
        condition(s,(int32_t)R(4)>=(int32_t)R(12));R(6)=R(19);if(R(17)&1)R(4)=R(12);
        R(2)=READ(0x0c0a7d54,4);R(1)=R(6);R(0)=R(4);if(!divide(s,ram,0x0c0a7d14))return 0;R(6)=R(0)+1;
    }
    R(0)=word(ram,0x0c0a7d22);R(13)+=R(6);WRITE(R(14)+R(0),R(13),2);goto done;
round_bonus:
    R(0)=25;R(7)=READ(R(14)+R(0),1);R(0)=R(7);condition(s,R(0)==2);R(6)=32;
    if(!(R(17)&1)){
        R(0)=word(ram,0x0c0a7e3e);R(3)=READ(R(14)+R(0),4);condition(s,R(4)==R(3));
        if(R(17)&1){
            R(0)=70;R(7)=word(ram,R(4)+R(0));R(0)=24;R(0)=READ(R(14)+R(0),1);condition(s,R(0)==1);R(7)&=65535;
            if(R(17)&1){R(3)=0;condition(s,(int32_t)R(3)>(int32_t)R(7));
                uint64_t sum=(uint64_t)R(7)+R(3)+(R(17)&1);R(7)=(uint32_t)sum;condition(s,sum>>32);half(s,7);}
            R(0)=24;R(2)=byte(ram,R(14)+R(0));condition(s,R(2)==0);R(13)+=R(7);
            if(R(17)&1){R(0)=70;R(1)=READ(R(4)+R(0),2);R(0)=word(ram,0x0c0a7e40);R(3)=word(ram,R(4)+R(0));
                condition(s,R(1)==R(3));if(R(17)&1)R(13)+=100;}
            R(2)=30;R(2)-=R(7);condition(s,(int32_t)R(2)>0);
            if(R(17)&1){R(2)=READ(0x0c0a7e50,4);R(1)=READ(R(14)+20,4);R(0)=R(6);
                if(!divide(s,ram,0x0c0a7db4))return 0;
                R(7)=READ(0x0c0a7e54,4);R(7)&=R(0);R(13)+=R(7);}
        }
    }
    R(0)=word(ram,0x0c0a7e42);WRITE(R(14)+R(0),R(13),2);R(12)=READ(R(14)+8,4);R(3)=READ(0x0c0a7e58,4);
    condition(s,(R(12)&R(3))==0);if(R(17)&1)goto done;
    R(0)=28;R(10)=byte(ram,R(14)+R(0));condition(s,R(13)&0x80000000u);R(13)<<=1;R(10)&=255;
    R(0)=R(10);condition(s,R(0)==1);R(7)=R(10);if(R(17)&1)R(7)++;
    R(2)=READ(0x0c0a7e50,4);R(1)=R(13);R(0)=R(7);if(!divide(s,ram,0x0c0a7de0))return 0;R(13)=R(0);
    R(0)=43;R(3)=READ(R(14)+60,4);WRITE(R(15),R(3),4);R(7)=byte(ram,R(14)+R(0));R(6)-=R(7);WRITE(R(15)+4,R(6),4);
    R(0)=word(ram,0x0c0a7e44);R(3)=READ(R(15),4);R(6)=word(ram,R(14)+R(0));condition(s,R(10)==R(3));
    if(R(17)&1){R(3)=READ(R(15)+4,4);R(2)=READ(0x0c0a7e5c,4);R(3)=0-R(3);
        int32_t n=(int32_t)R(3);R(2)=n>=0?R(2)<<(n&31):((n&31)?R(2)>>((-R(3))&31):0);R(6)|=R(2);}
    R(3)=16;R(0)=word(ram,0x0c0a7e44);condition(s,(R(12)&R(3))==0);WRITE(R(14)+R(0),R(6),2);
    if(!(R(17)&1)){R(2)=word(ram,0x0c0a7e46);R(13)+=R(2);}
    R(0)=word(ram,0x0c0a7e3e);R(3)=READ(R(14)+R(0),4);condition(s,R(3)==R(4));
    if(R(17)&1){R(0)=word(ram,0x0c0a7e48);WRITE(R(14)+R(0),R(7),1);}
    R(0)=word(ram,0x0c0a7e4a);R(3)=word(ram,R(14)+R(0));R(13)+=R(3);WRITE(R(14)+R(0),R(13),2);
clear_score:
    R(0)=word(ram,0x0c0a7e42);WRITE(R(14)+R(0),R(11),2);
done:
    R(15)+=8;R(0)=word(ram,0x0c0a7e4c);R(19)=pop(s,ram);WRITE(R(5)+R(0),R(11),2);R(16)=pop(s,ram);
    for(unsigned i=10;i<=13;i++)R(i)=pop(s,ram);
    s->pc=R(16);R(14)=pop(s,ram);return ram->oob==0;
}
