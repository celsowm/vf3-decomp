/* Resolve round winners, tied clocks and match completion, publish paired
 * round counters and play the appropriate result announcement. The final
 * tail enters the existing scene-audio input callback. Development candidate. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#define R(n) s->v[(n)]
#define F(n) s->v[21+(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
static void condition(vf3_matrix_state*s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static uint32_t byte(const vf3_ram_map*ram,uint32_t a){return (uint32_t)(int32_t)(int8_t)READ(a,1);}
static uint32_t word(const vf3_ram_map*ram,uint32_t a){return (uint32_t)(int32_t)(int16_t)READ(a,2);}
static void push(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t v){R(15)-=4;WRITE(R(15),v,4);}
static uint32_t pop(vf3_matrix_state*s,const vf3_ram_map*ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static int call(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t target,uint32_t ret)
{R(16)=ret;return vf3_matrix_family(target,s,ram)&&s->pc==ret;}
static void record_character_win(vf3_matrix_state*s,const vf3_ram_map*ram,unsigned actor)
{
    R(3)=97;R(2)=0xb70;R(3)+=R(actor);R(0)=READ(R(15)+20,4);R(3)=byte(ram,R(3));R(2)+=R(0);
    F(2)=0x3f800000;R(3)&=255;R(3)<<=2;R(3)+=R(2);vf3_matrix_load(s,ram,3,R(3));
    F(3)=vf3_fpu_binary(F(3),F(2),R(18),'+');vf3_matrix_store(s,ram,3,R(3));
}

int vf3_scene_round_decision_c(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    for(unsigned n=14;n>=8;n--)push(s,ram,R(n));push(s,ram,R(16));
    R(3)=READ(0x0c098d38,4);R(14)=READ(0x0c098d34,4);R(15)-=28;WRITE(R(15)+12,R(3),4);
    R(2)=READ(0x0c098d3c,4);WRITE(R(15)+24,R(2),4);R(4)=READ(0x0c098d40,4);
    R(3)=word(ram,0x0c098d22);R(3)+=R(4);WRITE(R(15)+4,R(3),4);
    R(2)=word(ram,0x0c098d24);R(2)+=R(4);WRITE(R(15)+20,R(2),4);
    R(3)=READ(0x0c098d44,4);WRITE(R(15)+16,R(3),4);R(3)=READ(0x0c098d4c,4);
    R(12)=READ(0x0c098d48,4);R(4)=READ(R(12)+60,4);if(!call(s,ram,R(3),0x0c098c98))return 0;
    R(3)=READ(0x0c098d4c,4);R(0)=64;R(4)=READ(R(12)+R(0),4);if(!call(s,ram,R(3),0x0c098ca0))return 0;
    R(2)=READ(R(14)+8,4);R(3)=READ(0x0c098d50,4);R(5)=READ(R(12)+16,4);condition(s,(R(2)&R(3))==0);R(7)=READ(R(12)+20,4);
    if(!(R(17)&1)){
        R(4)=word(ram,0x0c098d26);R(0)=70;R(8)=R(4);WRITE(R(15)+8,R(4),4);WRITE(R(5)+R(0),R(4),2);WRITE(R(7)+R(0),R(8),2);
    }else{
        R(0)=70;R(1)=word(ram,R(5)+R(0));R(0)=70;R(1)&=65535;WRITE(R(15)+8,R(1),4);R(8)=word(ram,R(7)+R(0))&65535;
    }
    R(0)=41;R(6)=READ(R(14)+60,4);R(11)=byte(ram,R(14)+R(0));R(0)=42;R(3)=byte(ram,R(14)+R(0));
    R(11)&=255;R(3)&=255;WRITE(R(15),R(3),4);R(13)=READ(R(14)+8,4);R(3)=READ(0x0c098d2c,4);
    R(10)=READ(0x0c098d54,4);condition(s,(R(13)&R(3))==0);R(4)=1;
    if(!(R(17)&1)){
        R(3)=READ(R(15)+8,4);condition(s,(int32_t)R(3)>(int32_t)R(8));R(9)=2;if(R(17)&1)goto first_wins;
        R(2)=READ(R(15)+8,4);condition(s,(int32_t)R(2)>=(int32_t)R(8));if(!(R(17)&1))goto second_wins;
        goto draw;
    }
    R(2)=word(ram,0x0c098d28);condition(s,(R(13)&R(2))==0);R(9)=R(4);if(R(17)&1)R(9)=0;
    R(2)=READ(R(14)+8,4);R(3)=READ(0x0c098d50,4);condition(s,(R(2)&R(3))==0);
    if(!(R(17)&1)){
        R(2)=READ(0x0c098d58,4);R(4)=READ(R(15)+4,4);R(4)+=18;if(!call(s,ram,R(2),0x0c098d18))return 0;
        R(0)&=255;condition(s,R(0)==0);R(4)=(R(17)&1)?56:53;
        if(!call(s,ram,R(10),0x0c098d62))return 0;goto publish;
    }
    R(2)=READ(R(5),4);R(3)=READ(0x0c098df4,4);condition(s,(R(2)&R(3))==0);if(R(17)&1)goto first_wins;
    R(1)=READ(R(7),4);R(3)=READ(0x0c098df4,4);condition(s,(R(1)&R(3))==0);if(R(17)&1)goto second_wins;
draw:
    /* A tie advances both counts. A repeated deciding tie uses the match mode
     * and the previous round's winner to select which count is rolled back. */
    R(0)=26;R(5)=byte(ram,R(14)+R(0));R(0)=27;R(7)=byte(ram,R(14)+R(0));R(0)=26;
    R(5)&=255;R(5)++;R(7)&=255;WRITE(R(14)+R(0),R(5),1);R(7)++;condition(s,(int32_t)R(5)>=(int32_t)R(6));
    R(3)=R(7);R(0)=27;R(3)-=R(6);WRITE(R(14)+R(0),R(7),1);R(8)=2;WRITE(R(15)+8,R(3),4);
    if(!(R(17)&1)){R(2)=READ(R(15)+8,4);condition(s,(int32_t)R(2)>=0);if(R(17)&1)goto second_match;goto announcement;}
    condition(s,(int32_t)R(7)>=(int32_t)R(6));if(!(R(17)&1))goto first_match;
    R(3)=READ(0x0c098df8,4);condition(s,(R(13)&R(3))==0);
    if(R(17)&1){R(5)--;R(2)=READ(0x0c098df8,4);R(0)=27;WRITE(R(14)+R(0),R(5),1);R(0)=26;R(13)|=R(2);WRITE(R(14)+R(0),R(5),1);goto announcement;}
    R(2)=READ(0x0c098dfc,4);R(0)=R(11);condition(s,R(0)==1);R(13)&=R(2);R(5)--;if(R(17)&1)goto rollback_second;
    R(0)=R(11);condition(s,R(0)==2);if(R(17)&1)goto rollback_first;
    R(0)=READ(R(15),4);condition(s,R(0)==1);if(R(17)&1)goto rollback_second;
    R(0)=READ(R(15),4);condition(s,R(0)==2);if(R(17)&1)goto rollback_first;
    R(6)=READ(R(15)+24,4);R(6)=READ(R(6),4);condition(s,(R(6)&R(4))==0);if(R(17)&1)goto rollback_first;
rollback_second:
    R(0)=27;WRITE(R(14)+R(0),R(5),1);goto first_match;
rollback_first:
    R(0)=26;WRITE(R(14)+R(0),R(5),1);goto second_match;
first_wins:
    R(0)=26;R(7)=byte(ram,R(14)+R(0))&255;R(7)++;WRITE(R(14)+R(0),R(7),1);
    R(0)=70;R(0)=word(ram,R(5)+R(0));condition(s,(int32_t)R(7)>=(int32_t)R(6));R(3)=READ(R(15)+16,4);WRITE(R(3)+2,R(0),2);R(8)=0;
    if(!(R(17)&1))goto first_pair;
    R(0)=R(11);condition(s,R(0)==3);if(R(17)&1)record_character_win(s,ram,5);
first_match:
    R(1)=0;R(3)=READ(0x0c098f34,4);R(0)=29;R(2)=READ(0x0c098f38,4);WRITE(R(14)+R(0),R(1),1);R(0)+=117;R(13)|=R(3);
    R(5)=READ(R(12)+44,4);R(13)&=R(2);R(3)=R(1);WRITE(R(5),R(1),4);R(3)=byte(ram,R(14)+R(0));R(0)=word(ram,0x0c098f24);
    R(1)=word(ram,0x0c098f22);WRITE(R(14)+R(0),R(3),1);R(0)=42;R(2)=byte(ram,R(14)+R(0));R(0)=word(ram,0x0c098f26);WRITE(R(14)+R(0),R(2),1);
    R(0)=R(11);condition(s,R(0)==3);R(13)&=R(1);if(!(R(17)&1))goto first_pair;
    R(0)=word(ram,0x0c098f28);R(0)=byte(ram,R(14)+R(0));condition(s,R(0)==1);
    if(!(R(17)&1)){R(3)=word(ram,0x0c098f2a);R(13)|=R(3);}
    R(0)=READ(R(15),4);condition(s,R(0)==1);
    if(!(R(17)&1)){
        R(0)=word(ram,0x0c098f28);WRITE(R(14)+R(0),R(4),1);R(0)=42;WRITE(R(14)+R(0),R(4),1);R(0)+=90;
    }else{
        R(0)=word(ram,0x0c098f2c);R(4)=READ(R(14)+R(0),4);R(0)=word(ram,0x0c098f2e);R(4)++;WRITE(R(14)+R(0),R(4),4);R(0)=word(ram,0x0c098f2c);
    }
    WRITE(R(14)+R(0),R(4),4);
first_pair:
    R(3)=READ(R(12)+16,4);WRITE(R(15),R(3),4);R(4)=READ(R(12)+20,4);goto publish_pair;
second_wins:
    R(0)=27;R(5)=byte(ram,R(14)+R(0))&255;R(5)++;WRITE(R(14)+R(0),R(5),1);R(0)=70;R(0)=word(ram,R(7)+R(0));
    condition(s,(int32_t)R(5)>=(int32_t)R(6));R(3)=READ(R(15)+16,4);WRITE(R(3)+2,R(0),2);R(8)=R(4);if(!(R(17)&1))goto second_pair;
    R(0)=R(11);condition(s,R(0)==3);if(R(17)&1)record_character_win(s,ram,7);
second_match:
    R(3)=READ(0x0c098f34,4);R(0)=29;R(2)=READ(0x0c098f38,4);R(13)|=R(3);WRITE(R(14)+R(0),R(4),1);R(5)=READ(R(12)+40,4);R(3)=0;R(0)+=117;
    WRITE(R(5),R(3),4);R(13)&=R(2);R(3)=byte(ram,R(14)+R(0));R(0)=word(ram,0x0c098f24);R(1)=word(ram,0x0c098f30);WRITE(R(14)+R(0),R(3),1);
    R(0)=42;R(2)=byte(ram,R(14)+R(0));R(0)=word(ram,0x0c098f26);WRITE(R(14)+R(0),R(2),1);R(0)=R(11);condition(s,R(0)==3);R(13)&=R(1);if(!(R(17)&1))goto second_pair;
    R(0)=word(ram,0x0c098f28);R(0)=byte(ram,R(14)+R(0));condition(s,R(0)==2);
    if(!(R(17)&1)){R(3)=word(ram,0x0c098f2a);R(13)|=R(3);}
    R(0)=READ(R(15),4);condition(s,R(0)==2);
    if(!(R(17)&1)){
        R(0)=word(ram,0x0c098f28);R(3)=2;R(2)=R(3);WRITE(R(14)+R(0),R(3),1);R(0)=42;WRITE(R(14)+R(0),R(2),1);R(0)+=90;
    }else{
        R(0)=word(ram,0x0c099034);R(4)=READ(R(14)+R(0),4);R(0)=word(ram,0x0c099036);R(4)++;WRITE(R(14)+R(0),R(4),4);R(0)=word(ram,0x0c099034);
    }
    WRITE(R(14)+R(0),R(4),4);
second_pair:
    R(3)=READ(R(12)+20,4);WRITE(R(15),R(3),4);R(4)=READ(R(12)+16,4);
publish_pair:
    R(0)=word(ram,0x0c099038);R(3)=READ(R(15),4);WRITE(R(14)+R(0),R(3),4);R(0)+=4;WRITE(R(14)+R(0),R(4),4);
announcement:
    /* Select tie, regular victory, deciding victory or rematch announcement. */
    R(3)=READ(0x0c099040,4);R(4)=READ(R(15)+4,4);R(4)+=18;if(!call(s,ram,R(3),0x0c098f62))return 0;
    R(0)&=255;R(4)=R(9);WRITE(R(15)+4,R(0),4);R(0)=R(8);condition(s,R(0)==2);R(5)=R(9);R(5)--;
    if(R(17)&1){R(2)=READ(R(14)+8,4);R(3)=READ(0x0c099044,4);condition(s,(R(2)&R(3))==0);if(R(17)&1){R(4)=45;goto announce;}}
    condition(s,R(4)==0);
    if(R(17)&1){
        R(4)=READ(R(15),4);R(0)=70;R(3)=word(ram,R(4)+R(0));R(0)=word(ram,0x0c09903a);R(3)&=65535;R(2)=word(ram,R(4)+R(0));condition(s,R(3)==R(2));R(4)=(R(17)&1)?46:50;
    }else{
        condition(s,R(5)==0);
        if(R(17)&1){R(2)=READ(R(15)+4,4);condition(s,R(2)==0);R(4)=(R(17)&1)?56:53;}
        else{R(3)=READ(R(15)+4,4);condition(s,R(3)==0);R(4)=(R(17)&1)?57:55;}
    }
announce:
    if(!call(s,ram,R(10),0x0c098fb8))return 0;
publish:
    R(3)=READ(0x0c09904c,4);R(0)=word(ram,0x0c09903c);R(4)=READ(R(12)+48,4);condition(s,(R(13)&R(3))==0);R(5)=READ(0x0c099048,4);WRITE(R(4)+R(0),R(5),4);
    if(!(R(17)&1)){
        R(2)=READ(0x0c099050,4);R(5)|=R(2);WRITE(R(4)+R(0),R(5),4);R(1)=READ(R(14)+8,4);R(3)=READ(0x0c099054,4);condition(s,(R(1)&R(3))==0);
        if(R(17)&1){R(0)=R(11);condition(s,R(0)==3);if(!(R(17)&1)){
            R(0)=43;R(3)=byte(ram,R(14)+R(0));R(2)=9;condition(s,(int32_t)R(3)>=(int32_t)R(2));if(R(17)&1){
                R(0)=41;R(3)=byte(ram,R(14)+R(0));R(0)=29;R(2)=byte(ram,R(14)+R(0));R(3)&=255;R(2)&=255;R(3)--;condition(s,R(3)==R(2));if(R(17)&1){R(3)=16;R(13)|=R(3);}
            }
        }}
    }
    R(0)=24;WRITE(R(14)+8,R(13),4);R(3)=96;WRITE(R(14)+R(0),R(9),1);R(0)=25;WRITE(R(14)+R(0),R(8),1);
    R(0)=16;R(12)=READ(R(15)+12,4);R(2)=29;WRITE(R(12)+12,R(3),4);R(3)=READ(0x0c099058,4);WRITE(R(12)+R(0),R(2),1);
    if(!call(s,ram,R(3),0x0c099014))return 0;R(1)=READ(0x0c09905c,4);if(!call(s,ram,R(1),0x0c09901a))return 0;
    R(15)+=28;R(0)=byte(ram,R(12)+11);R(16)=pop(s,ram);R(0)++;WRITE(R(12)+11,R(0),1);
    for(unsigned n=8;n<=14;n++)R(n)=pop(s,ram);
    return vf3_matrix_family(0x0c099060,s,ram);
}
