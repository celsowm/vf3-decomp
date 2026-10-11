/* Scene-nine round transition, callable 0x0c09a0a8 / owner 0x8c09a0c0.
 * A player result selects the next scene; otherwise input advances a timeout.
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
static void input_shift(vf3_matrix_state*s)
{int32_t n=(int32_t)R(4);R(6)=n>=0?R(6)<<(n&31):((n&31)?(uint32_t)((int32_t)R(6)>>((-R(4))&31)):((int32_t)R(6)<0?0xffffffffu:0));}
static int request(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t reg,uint32_t ret)
{R(16)=ret;return vf3_matrix_family(R(reg),s,ram)&&s->pc==R(16);}
int vf3_round_transition_c(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    push(s,ram,R(14));R(0)=41;push(s,ram,R(13));R(7)=1;push(s,ram,R(12));push(s,ram,R(11));R(11)=0;
    push(s,ram,R(10));R(10)=4;push(s,ram,R(9));push(s,ram,R(8));R(12)=READ(0x0c09a14c,4);push(s,ram,R(16));
    R(5)=READ(R(12)+R(0),1);R(8)=READ(0x0c09a150,4);R(3)=READ(0x0c09a154,4);R(0)=R(5);
    R(13)=READ(R(12)+8,4);R(14)=READ(0x0c09a144,4);condition(s,R(0)==1);R(4)=READ(R(3),4);
    if(R(17)&1){
        R(3)=READ(0x0c09a158,4);condition(s,(R(13)&R(3))==0);if(R(17)&1)goto player_timeout;
        R(2)=READ(0x0c09a15c,4);R(13)&=R(2);R(9)=R(4);
    }else{
        R(0)=R(5);R(3)=READ(0x0c09a160,4);condition(s,R(0)==2);R(6)=READ(R(3),4);if(!(R(17)&1))goto general_timeout;
        R(3)=READ(0x0c09a164,4);condition(s,(R(13)&R(3))==0);if(R(17)&1)goto player_timeout;
        R(2)=READ(0x0c09a168,4);R(9)=R(6);R(13)&=R(2);
    }
    /* Consume a player result and request the transition cue. */
    R(2)=READ(0x0c09a16c,4);R(5)=0;R(4)=R(8);if(!request(s,ram,2,0x0c09a102))return 0;
    R(3)=READ(0x0c09a170,4);R(1)=10;R(4)=READ(R(9),4);R(2)=READ(0x0c09a174,4);R(13)&=R(3);R(4)|=R(1);R(13)|=R(2);
    WRITE(R(9),R(4),4);condition(s,(R(13)&R(10))==0);WRITE(R(12)+8,R(13),4);R(4)=7;R(0)=R(4);WRITE(R(14)+10,R(0),1);
    R(0)=(R(17)&1)?2:R(11);WRITE(R(14)+11,R(0),1);goto done;
player_timeout:
    R(0)=word(ram,0x0c09a25e);R(3)=word(ram,0x0c09a260);R(6)=READ(R(14)+R(0),4);R(0)=29;
    R(4)=READ(R(12)+R(0),1);R(5)=READ(R(14)+12,4);R(4)^=R(7);R(4)<<=2;condition(s,R(4)&0x80000000u);R(4)<<=1;
    condition(s,(int32_t)R(5)>(int32_t)R(3));R(4)=0-R(4);input_shift(s);
    if(!(R(17)&1)){R(2)=word(ram,0x0c09a262);condition(s,(R(6)&R(2))==0);if(!(R(17)&1)){R(5)-=32;WRITE(R(14)+12,R(5),4);}}
    condition(s,(int32_t)R(5)>0);if(R(17)&1)goto done;
    R(0)=word(ram,0x0c09a264);R(4)=8;R(2)=byte(ram,R(12)+R(0));condition(s,R(2)==0);R(4)&=R(13);
    if(R(17)&1){condition(s,R(4)==0);if(!(R(17)&1))goto expired_request;}
    else {condition(s,R(4)==0);if(!(R(17)&1)){R(3)=63;WRITE(R(12)+R(0),R(7),1);WRITE(R(14)+12,R(3),4);goto done;}}
    WRITE(R(14)+12,R(11),4);R(0)=18;goto next_scene;
expired_request:
    R(2)=READ(0x0c09a26c,4);R(5)=0;R(4)=R(8);if(!request(s,ram,2,0x0c09a1d0))return 0;
    R(3)=READ(R(12)+8,4);condition(s,(R(3)&R(10))==0);WRITE(R(14)+12,R(11),4);
    R(0)=(R(17)&1)?16:18;goto next_scene;
general_timeout:
    R(0)=word(ram,0x0c09a266);R(0)=byte(ram,R(12)+R(0));condition(s,R(0)==1);
    if(!(R(17)&1)){
        R(3)=READ(0x0c09a270,4);condition(s,(R(13)&R(3))==0);if(R(17)&1)goto idle_timeout;
        R(0)=word(ram,0x0c09a268);R(2)=READ(0x0c09a274,4);R(5)=byte(ram,R(12)+R(0));R(13)|=R(2);R(5)++;
    }else{
        R(2)=READ(0x0c09a278,4);condition(s,(R(13)&R(2))==0);if(R(17)&1)goto idle_timeout;
        R(0)=word(ram,0x0c09a268);R(3)=READ(0x0c09a27c,4);R(5)=byte(ram,R(12)+R(0));R(13)|=R(3);R(5)+=2;
    }
    R(0)=word(ram,0x0c09a268);WRITE(R(12)+R(0),R(5),1);R(5)=0;R(3)=READ(0x0c09a26c,4);R(4)=R(8);
    if(!request(s,ram,3,0x0c09a212))return 0;
    R(2)=READ(0x0c09a280,4);R(13)&=R(2);WRITE(R(12)+8,R(13),4);R(0)=R(10);goto next_scene;
idle_timeout:
    R(0)=word(ram,0x0c09a25e);R(3)=word(ram,0x0c09a26a);R(6)=READ(R(14)+R(0),4);R(0)=29;
    R(4)=READ(R(12)+R(0),1);R(5)=READ(R(14)+12,4);R(4)^=R(7);R(4)<<=2;condition(s,R(4)&0x80000000u);R(4)<<=1;
    condition(s,(int32_t)R(5)>(int32_t)R(3));R(4)=0-R(4);input_shift(s);
    if(!(R(17)&1)){R(2)=word(ram,0x0c09a262);condition(s,(R(6)&R(2))==0);if(!(R(17)&1)){R(5)-=32;WRITE(R(14)+12,R(5),4);}}
    condition(s,(int32_t)R(5)>0);if(R(17)&1)goto done;
    R(0)=6;WRITE(R(14)+12,R(11),4);
next_scene:
    WRITE(R(14)+10,R(0),1);
done:
    R(16)=pop(s,ram);for(unsigned i=8;i<=13;i++)R(i)=pop(s,ram);s->pc=R(16);R(14)=pop(s,ram);return ram->oob==0;
}
