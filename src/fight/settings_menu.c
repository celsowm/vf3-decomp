/* Settings menu input/state update, callable 0x0c0c95f4 / owner 0x8c0c9610.
 * Original limit tables and signed selector arithmetic are retained.
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
/* The three selector chains load the same fields from different literal slots. */
static int option(vf3_matrix_state*s,const vf3_ram_map*ram,unsigned chain)
{
    static const uint32_t pools[3][6]={
        {0x0c0c979c,0x0c0c979e,0x0c0c97a0,0x0c0c97a2,0x0c0c97a4,0x0c0c97a6},
        {0x0c0c979c,0x0c0c979e,0x0c0c9876,0x0c0c9878,0x0c0c987a,0x0c0c987c},
        {0x0c0c9882,0x0c0c9884,0x0c0c9876,0x0c0c9878,0x0c0c987a,0x0c0c987c}};
    R(0)=R(4);
    for(unsigned i=0;i<6;i++){condition(s,R(0)==i);if(R(17)&1){R(0)=word(ram,pools[chain][i]);return 1;}}
    return 0;
}
int vf3_settings_menu_c(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    push(s,ram,R(14));R(7)=1;push(s,ram,R(13));R(6)=3;push(s,ram,R(12));R(12)=0;
    push(s,ram,R(11));push(s,ram,R(10));push(s,ram,R(9));R(0)=word(ram,0x0c0c96c2);
    R(13)=READ(0x0c0c96d0,4);R(14)=READ(0x0c0c96d4,4);R(5)=READ(R(13)+R(0),4);R(0)=word(ram,0x0c0c96c6);push(s,ram,R(16));
    R(11)=READ(0x0c0c96dc,4);R(4)=READ(0x0c0c96d8,4);R(0)=byte(ram,R(14)+R(0));R(11)&=R(5);
    R(10)=word(ram,0x0c0c96c4);R(15)-=8;condition(s,R(0)==1);R(4)&=R(5);R(10)&=R(5);if(R(17)&1)goto active;
    condition(s,R(0)==2);if(R(17)&1)goto phase_exit;
    condition(s,R(0)==3);if(R(17)&1)goto phase_exit;
    R(0)=word(ram,0x0c0c96c8);condition(s,R(4)==0);R(5)=byte(ram,R(14)+R(0));
    if(!(R(17)&1)){
        R(0)=R(5);condition(s,R(0)==0);R(4)=97;if(R(17)&1)goto defaults;
        condition(s,R(0)==1);if(R(17)&1){R(0)=word(ram,0x0c0c9990);R(1)=2;WRITE(R(14)+R(0),R(1),1);R(0)=16;WRITE(R(13)+R(0),R(4),1);goto done;}
        condition(s,R(0)==2);if(R(17)&1){R(0)=word(ram,0x0c0c9990);R(3)=99;WRITE(R(14)+R(0),R(6),1);R(0)=16;WRITE(R(13)+R(0),R(3),1);goto done;}
        R(0)=R(12);WRITE(R(13)+11,R(0),1);goto done;
    }
    condition(s,R(11)==0);if(R(17)&1){condition(s,R(10)==0);R(7)=0xffffffffu;if(R(17)&1)goto done;}
    R(0)=word(ram,0x0c0c96ca);R(4)=R(5)+R(7);WRITE(R(14)+R(0),R(5),1);R(4)&=R(6);goto selection_changed;
active:
    R(3)=16;R(0)=word(ram,0x0c0c96c8);condition(s,(R(5)&R(3))==0);R(4)=byte(ram,R(14)+R(0));if(!(R(17)&1))goto exit_menu;
    condition(s,R(11)==0);R(9)=R(7);if(!(R(17)&1))goto adjust;
    condition(s,R(10)==0);R(9)=0xffffffffu;if(!(R(17)&1))goto adjust;
    R(0)=word(ram,0x0c0c96cc);R(3)=READ(0x0c0c96e0,4);R(6)=READ(R(13)+R(0),4);condition(s,(R(6)&R(3))==0);
    if(R(17)&1){
        R(2)=READ(0x0c0c96e4,4);condition(s,(R(5)&R(2))==0);if(!(R(17)&1))goto forward;
        R(3)=READ(0x0c0c96e8,4);condition(s,(R(5)&R(3))==0);if(R(17)&1)goto done;
        R(0)=word(ram,0x0c0c987e);condition(s,(int32_t)R(4)>0);WRITE(R(14)+R(0),R(4),1);if(!(R(17)&1))goto exit_menu;
        R(4)--;goto selection_changed;
    }
    R(1)=READ(0x0c0c96ec,4);condition(s,(R(5)&R(1))==0);if(!(R(17)&1))goto exit_menu;goto done;
adjust:
    if(option(s,ram,0))R(5)=byte(ram,R(14)+R(0));
    R(13)=R(4);R(13)<<=2;WRITE(R(15),R(13),4);R(0)=READ(0x0c0c97a8,4);R(13)=READ(R(13)+R(0),4);
    R(0)=R(4);condition(s,R(0)==2);
    if(R(17)&1){
        R(0)=word(ram,0x0c0c979e);R(0)=byte(ram,R(14)+R(0));WRITE(R(15)+4,R(0),1);R(7)=byte(ram,R(13)+R(0));
        R(0)=byte(ram,R(15)+4);condition(s,R(0)==2);
        if(R(17)&1){R(0)=word(ram,0x0c0c979c);R(3)=byte(ram,R(14)+R(0));condition(s,(R(3)&R(6))==0);if(R(17)&1)R(7)++;}
    }else R(7)=byte(ram,R(13));
    R(0)=READ(0x0c0c97ac,4);R(5)+=R(9);R(2)=READ(R(15),4);condition(s,(int32_t)R(5)>(int32_t)R(7));
    R(6)=READ(R(2)+R(0),4);R(6)=byte(ram,R(6));if(R(17)&1)R(5)=R(6);
    condition(s,(int32_t)R(5)>=(int32_t)R(6));R(0)=R(4);if(!(R(17)&1))R(5)=R(7);
    if(option(s,ram,1))WRITE(R(14)+R(0),R(5),1);
    goto done;
selection_changed:
    R(0)=word(ram,0x0c0c9880);WRITE(R(14)+R(0),R(4),1);goto done;
forward:
    R(3)=5;R(0)=word(ram,0x0c0c987e);condition(s,(int32_t)R(4)>=(int32_t)R(3));WRITE(R(14)+R(0),R(4),1);
    if(!(R(17)&1)){
        R(0)=word(ram,0x0c0c9880);R(4)++;R(5)=R(4);R(5)<<=2;WRITE(R(14)+R(0),R(4),1);
        R(0)=READ(0x0c0c9888,4);R(5)=READ(R(5)+R(0),4);R(0)=R(4);condition(s,R(0)==0);R(5)=byte(ram,R(5));
        if(option(s,ram,2))WRITE(R(14)+R(0),R(5),1);
        goto done;
    }
    /* The original settings callback is RTS/NOP; keep its argument/stack ABI. */
    R(0)=word(ram,0x0c0c987c);R(3)=byte(ram,R(14)+R(0));R(0)--;push(s,ram,R(3));
    R(2)=byte(ram,R(14)+R(0));R(0)--;push(s,ram,R(2));R(7)=byte(ram,R(14)+R(0));R(0)--;
    R(6)=byte(ram,R(14)+R(0));R(0)--;R(3)=READ(0x0c0c988c,4);R(5)=byte(ram,R(14)+R(0));R(0)--;
    R(16)=0x0c0c9854;R(4)=byte(ram,R(14)+R(0));s->pc=R(16);R(15)+=8;goto exit_menu;
phase_exit:
    condition(s,R(4)==0);if(R(17)&1)goto done;
exit_menu:
    R(0)=word(ram,0x0c0c9886);R(3)=93;R(4)=byte(ram,R(14)+R(0));R(0)+=2;R(4)--;
    WRITE(R(14)+R(0),R(4),1);R(0)++;WRITE(R(14)+R(0),R(4),1);R(0)-=3;WRITE(R(14)+R(0),R(12),1);
    R(0)=16;WRITE(R(13)+R(0),R(3),1);goto done;
defaults:
    R(0)=word(ram,0x0c0c998e);R(3)=95;WRITE(R(14)+R(0),R(4),1);R(0)++;WRITE(R(14)+R(0),R(7),1);
    R(0)++;WRITE(R(14)+R(0),R(7),1);R(0)++;WRITE(R(14)+R(0),R(12),1);R(0)++;WRITE(R(14)+R(0),R(12),1);
    R(0)++;WRITE(R(14)+R(0),R(12),1);R(0)-=63;WRITE(R(14)+R(0),R(12),1);R(0)++;WRITE(R(14)+R(0),R(12),1);
    R(0)-=3;WRITE(R(14)+R(0),R(7),1);R(0)=16;WRITE(R(13)+R(0),R(3),1);
done:
    R(15)+=8;R(3)=READ(0x0c0c999c,4);R(16)=pop(s,ram);for(unsigned i=9;i<=13;i++)R(i)=pop(s,ram);R(14)=pop(s,ram);
    return vf3_matrix_family(R(3),s,ram);
}
