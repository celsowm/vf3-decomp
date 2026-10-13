/* Original options-menu controller (entry 0x8c09bc1c, owner 0x8c09bc2e).
 * Development candidate: preserve guest ABI while expressing navigation,
 * option-specific wrap ranges, configuration actions and menu transitions.
 * The original sound, configuration and value-refresh helpers still execute. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
static void condition(vf3_matrix_state *s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static uint32_t word(const vf3_ram_map *ram,uint32_t a){return (uint32_t)(int32_t)(int16_t)READ(a,2);}
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t v){R(15)-=4;WRITE(R(15),v,4);}
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static int call(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t target,uint32_t returned){R(16)=returned;return vf3_matrix_family(target,s,ram);}

/* The first eight rows use distinct integer ranges. Keep the original
 * temporary registers and comparison result observable to strict replay. */
static void decrease(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    unsigned selected=R(0);
    condition(s,selected<=7);
    switch(selected){
    case 0:
        R(0)=word(ram,0x0c09bcfc);R(3)=READ(R(14)+R(0),4);R(3)--;WRITE(R(14)+R(0),R(3),4);
        R(2)=READ(R(14)+R(0),4);condition(s,(int32_t)R(2)>=(int32_t)R(9));
        if(!(R(17)&1)){R(1)=5;WRITE(R(14)+R(0),R(1),4);}break;
    case 1: case 2:
        R(0)=word(ram,0x0c09bcfc);R(2)=READ(R(14)+R(0),4);R(2)--;WRITE(R(14)+R(0),R(2),4);
        R(3)=READ(R(14)+R(0),4);condition(s,(int32_t)R(3)>=0);
        if(!(R(17)&1)){R(1)=3;WRITE(R(14)+R(0),R(1),4);}break;
    case 3: case 4:
        R(0)=word(ram,0x0c09bdd0);R(2)=READ(R(14)+R(0),4);R(2)-=20;WRITE(R(14)+R(0),R(2),4);
        R(3)=word(ram,0x0c09bdd2);R(1)=READ(R(14)+R(0),4);condition(s,(int32_t)R(1)>=(int32_t)R(3));
        if(!(R(17)&1)){R(2)=word(ram,0x0c09bdd4);WRITE(R(14)+R(0),R(2),4);}break;
    case 5:
        R(0)=word(ram,0x0c09bdd0);R(2)=READ(R(14)+R(0),4);R(2)--;WRITE(R(14)+R(0),R(2),4);
        R(3)=READ(R(14)+R(0),4);condition(s,(int32_t)R(3)>=0);
        if(!(R(17)&1)){R(0)=word(ram,0x0c09bdd0);WRITE(R(14)+R(0),R(11),4);}break;
    case 6:
        R(0)=word(ram,0x0c09bdd0);R(3)=READ(R(14)+R(0),4);R(3)--;WRITE(R(14)+R(0),R(3),4);
        R(2)=READ(R(14)+R(0),4);condition(s,(int32_t)R(2)>=0);
        if(!(R(17)&1))WRITE(R(14)+R(0),R(9),4);break;
    case 7:
        R(0)=word(ram,0x0c09bdd0);R(2)=READ(R(14)+R(0),4);R(2)--;WRITE(R(14)+R(0),R(2),4);
        R(3)=READ(R(14)+R(0),4);condition(s,(int32_t)R(3)>=0);
        if(!(R(17)&1)){R(0)=word(ram,0x0c09bdd0);WRITE(R(14)+R(0),R(11),4);}break;
    default:break;
    }
}

static void increase(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    unsigned selected=R(0);
    condition(s,selected<=7);
    switch(selected){
    case 0:
        R(0)=word(ram,0x0c09bdd0);R(2)=5;R(3)=READ(R(14)+R(0),4);R(3)++;WRITE(R(14)+R(0),R(3),4);
        R(1)=READ(R(14)+R(0),4);condition(s,(int32_t)R(1)>(int32_t)R(2));
        if(R(17)&1)WRITE(R(14)+R(0),R(9),4);break;
    case 1:
        R(0)=word(ram,0x0c09bdd0);R(3)=3;R(2)=READ(R(14)+R(0),4);R(2)++;WRITE(R(14)+R(0),R(2),4);
        R(1)=READ(R(14)+R(0),4);condition(s,(int32_t)R(1)>(int32_t)R(3));
        if(R(17)&1){R(0)=word(ram,0x0c09beb8);WRITE(R(14)+R(0),R(10),4);}break;
    case 2:
        R(0)=word(ram,0x0c09bdd0);R(2)=3;R(3)=READ(R(14)+R(0),4);R(3)++;WRITE(R(14)+R(0),R(3),4);
        R(1)=READ(R(14)+R(0),4);condition(s,(int32_t)R(1)>(int32_t)R(2));
        if(R(17)&1){R(0)=word(ram,0x0c09beb8);WRITE(R(14)+R(0),R(10),4);}break;
    case 3: case 4:
        R(0)=word(ram,0x0c09beb8);R(2)=READ(R(14)+R(0),4);R(2)+=20;WRITE(R(14)+R(0),R(2),4);
        R(3)=word(ram,0x0c09beba);R(1)=READ(R(14)+R(0),4);condition(s,(int32_t)R(1)>(int32_t)R(3));
        if(R(17)&1){R(2)=word(ram,0x0c09bebc);WRITE(R(14)+R(0),R(2),4);}break;
    case 5: case 7:
        R(0)=word(ram,0x0c09beb8);R(2)=READ(R(14)+R(0),4);R(2)++;WRITE(R(14)+R(0),R(2),4);
        R(3)=READ(R(14)+R(0),4);condition(s,(int32_t)R(3)>(int32_t)R(11));
        if(R(17)&1){R(0)=word(ram,0x0c09beb8);WRITE(R(14)+R(0),R(10),4);}break;
    case 6:
        R(0)=word(ram,0x0c09beb8);R(3)=READ(R(14)+R(0),4);R(3)++;WRITE(R(14)+R(0),R(3),4);
        R(2)=READ(R(14)+R(0),4);condition(s,(int32_t)R(2)>(int32_t)R(9));
        if(R(17)&1){R(0)=word(ram,0x0c09beb8);WRITE(R(14)+R(0),R(10),4);}break;
    default:break;
    }
}

int vf3_options_menu_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    push(s,ram,R(14));push(s,ram,R(13));push(s,ram,R(12));push(s,ram,R(11));push(s,ram,R(10));R(10)=0;
    push(s,ram,R(9));R(9)=2;push(s,ram,R(8));push(s,ram,R(16));
    R(12)=READ(0x0c09bd00,4);R(14)=READ(0x0c09bd04,4);R(8)=READ(0x0c09bd08,4);R(15)-=4;R(11)=1;
    if(!call(s,ram,0x0c09af6c,0x0c09bc3c))return 0;
    R(13)=R(0);R(0)=125;R(2)=64;WRITE(R(14)+12,R(2),4);R(2)=16;condition(s,(R(13)&R(2))==0);
    WRITE(R(14)+24,R(10),4);WRITE(R(14)+R(0),R(10),1);WRITE(R(14)+20,R(10),4);
    R(0)=word(ram,0x0c09bcf8);R(3)=READ(R(14)+R(0),4);WRITE(R(15),R(3),4);
    if(!(R(17)&1)){
        R(4)=word(ram,0x0c09bcfa);if(!call(s,ram,R(12),0x0c09bc5c))return 0;
        R(0)=word(ram,0x0c09bcf8);R(2)=READ(R(14)+R(0),4);R(2)--;WRITE(R(14)+R(0),R(2),4);
        R(3)=READ(R(14)+R(0),4);condition(s,(int32_t)R(3)>=0);
        if(!(R(17)&1)){R(1)=11;WRITE(R(14)+R(0),R(1),4);}
    }
    R(3)=32;condition(s,(R(13)&R(3))==0);
    if(!(R(17)&1)){
        R(4)=word(ram,0x0c09bcfa);if(!call(s,ram,R(12),0x0c09bc7a))return 0;
        R(0)=word(ram,0x0c09bcf8);R(2)=12;R(3)=READ(R(14)+R(0),4);R(3)++;WRITE(R(14)+R(0),R(3),4);
        R(1)=READ(R(14)+R(0),4);condition(s,(int32_t)R(1)>=(int32_t)R(2));if(R(17)&1)WRITE(R(14)+R(0),R(10),4);
    }
    R(0)=word(ram,0x0c09bcf8);R(2)=READ(R(15),4);R(3)=READ(R(14)+R(0),4);condition(s,R(2)==R(3));
    if(!(R(17)&1)){
        R(0)=word(ram,0x0c09bcfc);R(5)=READ(R(14)+R(0),4);R(4)=READ(R(15),4);
        if(!call(s,ram,0x0c09bad0,0x0c09bc9e))return 0;
    }
    R(2)=64;condition(s,(R(13)&R(2))==0);
    if(!(R(17)&1)){
        R(4)=127;if(!call(s,ram,R(12),0x0c09bca8))return 0;
        R(0)=word(ram,0x0c09bcf8);R(0)=READ(R(14)+R(0),4);decrease(s,ram);
        R(0)=word(ram,0x0c09bdd0);R(5)=READ(R(14)+R(0),4);R(0)+=4;R(4)=READ(R(14)+R(0),4);
        if(!call(s,ram,0x0c09bad0,0x0c09bd62))return 0;
    }
    R(2)=word(ram,0x0c09bdd6);condition(s,(R(13)&R(2))==0);
    if(!(R(17)&1)){
        R(4)=127;if(!call(s,ram,R(12),0x0c09bd6c))return 0;
        R(0)=word(ram,0x0c09bdd8);R(0)=READ(R(14)+R(0),4);increase(s,ram);
        R(0)=word(ram,0x0c09beb8);R(5)=READ(R(14)+R(0),4);R(0)+=4;R(4)=READ(R(14)+R(0),4);
        if(!call(s,ram,0x0c09bad0,0x0c09be30))return 0;
    }
    R(2)=4;condition(s,(R(13)&R(2))==0);
    if(!(R(17)&1)){
        R(4)=word(ram,0x0c09bebe);if(!call(s,ram,R(12),0x0c09be3c))return 0;
        R(0)=word(ram,0x0c09bec0);R(0)=READ(R(14)+R(0),4);
        condition(s,R(0)==8);
        if(R(17)&1){R(0)=10;WRITE(R(14)+11,R(0),1);R(3)=119;R(0)=16;WRITE(R(14)+R(0),R(3),1);}
        else{
            condition(s,R(0)==9);
            if(R(17)&1){R(0)=12;WRITE(R(14)+11,R(0),1);R(3)=120;R(0)=16;WRITE(R(14)+R(0),R(3),1);}
            else{
                condition(s,R(0)==10);
                if(R(17)&1){
                    R(3)=READ(0x0c09bec4,4);R(4)=0;if(!call(s,ram,R(3),0x0c09be6a))return 0;
                    R(2)=READ(0x0c09bec8,4);R(4)=R(2);WRITE(R(15),R(2),4);R(3)=READ(0x0c09becc,4);R(4)++;
                    if(!call(s,ram,R(3),0x0c09be76))return 0;
                    R(1)=word(ram,0x0c09bec2);R(1)+=R(8);WRITE(R(1),R(0),1);
                    R(4)=READ(R(15),4);R(3)=READ(0x0c09becc,4);R(4)+=14;if(!call(s,ram,R(3),0x0c09be84))return 0;
                    R(0)&=255;condition(s,R(0)==0);
                    if(R(17)&1){R(0)=READ(R(8)+8,4);R(0)|=8;WRITE(R(8)+8,R(0),4);}
                    else{R(2)=READ(R(8)+8,4);R(3)=0xfffffff7u;R(2)&=R(3);WRITE(R(8)+8,R(2),4);}
                }else{
                    condition(s,R(0)==11);
                    if(R(17)&1){R(0)=R(11);R(3)=114;WRITE(R(14)+11,R(0),1);R(0)=16;WRITE(R(14)+R(0),R(3),1);}
                }
            }
        }
    }
    R(1)=10;condition(s,(R(13)&R(1))==0);
    if(!(R(17)&1)){
        R(2)=8;condition(s,(R(13)&R(2))==0);
        R(4)=word(ram,(R(17)&1)?0x0c09bf94:0x0c09bebe);
        if(!call(s,ram,R(12),0x0c09bed6))return 0;
        R(3)=READ(0x0c09bfa4,4);R(4)=READ(0x0c09bfa0,4);R(5)=0;
        if(!call(s,ram,R(3),0x0c09bede))return 0;
        R(0)=R(11);WRITE(R(14)+11,R(0),1);R(0)=16;R(3)=114;WRITE(R(14)+R(0),R(3),1);
    }
    R(15)+=4;R(16)=pop(s,ram);
    for(unsigned n=8;n<=14;n++)R(n)=pop(s,ram);
    s->pc=R(16);return ram->oob==0;
}
