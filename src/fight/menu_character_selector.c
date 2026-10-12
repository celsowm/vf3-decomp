/* Character menu refresh: retire prior tiles, resolve active actor metadata,
 * and rebuild the selected character's icon row and command captions.
 * Development candidate; original helpers and descriptor callbacks execute. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
static void condition(vf3_matrix_state *s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static void shift(vf3_matrix_state *s,unsigned n){condition(s,R(n)>>31);R(n)<<=1;}
static uint32_t byte(const vf3_ram_map *ram,uint32_t a){return (uint32_t)(int32_t)(int8_t)READ(a,1);}
static uint32_t word(const vf3_ram_map *ram,uint32_t a){return (uint32_t)(int32_t)(int16_t)READ(a,2);}
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t v){R(15)-=4;WRITE(R(15),v,4);}
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static int call(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t target,uint32_t returned){R(16)=returned;return vf3_matrix_family(target,s,ram);}

/* Selection bits are derived from the two original task status words. The
 * descriptor-clear leaf scans exactly 120 records, each 68 bytes wide. */
int vf3_menu_selection_helpers_c(uint32_t entry,vf3_matrix_state *s,const vf3_ram_map *ram)
{
    if(entry==0x0c07cf10){
        R(7)=READ(0x0c07cf9c,4);R(3)=2;R(4)=0;R(5)=READ(R(7)+40,4);R(5)=READ(R(5),4);
        condition(s,(R(5)&R(3))==0);R(6)=4;
        if(!(R(17)&1))R(4)=1;
        else {condition(s,(R(5)&R(6))==0);if(!(R(17)&1))R(4)=1;}
        R(5)=READ(R(7)+44,4);R(3)=2;R(5)=READ(R(5),4);condition(s,(R(5)&R(3))==0);
        if(!(R(17)&1))R(4)+=2;
        else {condition(s,(R(5)&R(6))==0);if(!(R(17)&1))R(4)+=2;}
        R(3)=READ(0x0c07cfa0,4);WRITE(R(3),R(4),1);R(0)=(uint32_t)(int32_t)(int8_t)R(4);
    }else if(entry==0x0c0c1f9c){
        R(6)=READ(R(5)+12,4);R(5)=0;R(7)=R(5);R(1)=120;
        do{
            R(0)=word(ram,R(6)+2)&65535u;condition(s,R(0)==R(4));
            if(R(17)&1)WRITE(R(6),R(5),2);
            R(7)++;condition(s,R(7)>=R(1));R(6)+=68;
        }while(!(R(17)&1));
    }else if(entry==0x0c07b6f4){
        push(s,ram,R(16));R(15)-=12;WRITE(R(15),R(4),4);WRITE(R(15)+4,R(5),4);WRITE(R(15)+8,R(7),4);
        R(7)=0;R(3)=READ(R(15)+16,4);push(s,ram,R(3));R(2)=READ(R(15)+12,4);push(s,ram,R(2));
        R(5)=READ(R(15)+12,4);R(3)=READ(0x0c07b730,4);R(2)=READ(0x0c07b72c,4);R(5)|=R(3);R(4)=READ(R(15)+8,4);
        if(!call(s,ram,R(2),0x0c07b714))return 0;
        R(15)+=20;R(16)=pop(s,ram);
    }else return 0;
    s->pc=R(16);return ram->oob==0;
}

int vf3_menu_character_selector_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    for(unsigned n=14;n>=8;n--)push(s,ram,R(n));
    R(4)=READ(0x0c07cfa4,4);R(2)=READ(0x0c07cfa0,4);push(s,ram,R(16));R(3)=byte(ram,R(2));
    R(11)=R(4)+44;R(12)=R(4);R(15)-=20;WRITE(R(15),R(3),1);
    if(!call(s,ram,0x0c07cf10,0x0c07cf60))return 0;
    R(14)=0;WRITE(R(15)+4,R(0),1);R(13)=READ(0x0c07cfa8,4);R(8)=R(14);R(9)=word(ram,0x0c07cf96);R(10)=8;
    for(;;){
        condition(s,(int32_t)R(8)>=(int32_t)R(10));if(R(17)&1)break;
        R(5)=R(12);R(4)=R(9);if(!call(s,ram,R(13),0x0c07cf74))return 0;R(9)++;R(8)++;
    }
    R(8)=word(ram,0x0c07cf98);R(9)=R(8)-116;
    for(;;){
        condition(s,(int32_t)R(9)>(int32_t)R(8));if(R(17)&1)break;
        R(5)=R(12);R(4)=R(9);if(!call(s,ram,R(13),0x0c07cf8a))return 0;R(9)++;
    }
    R(9)=word(ram,0x0c07cf9a);
    for(;;){
        R(2)=word(ram,0x0c07d0d8);condition(s,(int32_t)R(9)>(int32_t)R(2));if(R(17)&1)break;
        R(5)=R(12);R(4)=R(9);if(!call(s,ram,R(13),0x0c07cfb2))return 0;R(9)++;
    }
    R(0)=byte(ram,R(15)+4);R(3)=byte(ram,R(15));R(9)=R(0);condition(s,R(9)==R(3));
    if(!(R(17)&1)){
        R(13)=READ(0x0c07d0f4,4);
        static const uint32_t pools[][4]={
            {0x0c07d0da,0x0c07d0dc,11,0x0c07cfd2},{0x0c07d0de,0x0c07d0e0,11,0x0c07cfde},
            {0x0c07d0da,0x0c07d0e2,12,0x0c07cfea},{0x0c07d0de,0x0c07d0e4,12,0x0c07cff6},
            {0x0c07d0e6,0x0c07d0e8,12,0x0c07d002}};
        for(unsigned n=0;n<5;n++){
            R(7)=0;push(s,ram,R(14));R(4)=word(ram,pools[n][0]);R(5)=word(ram,pools[n][1]);R(6)=R(pools[n][2]);
            if(!call(s,ram,R(13),pools[n][3]))return 0;
        }
        R(15)+=20;
    }
    R(13)=READ(0x0c07d0f8,4);R(7)=0;push(s,ram,R(14));R(5)=word(ram,0x0c07d0dc);R(4)=word(ram,0x0c07d0da);R(6)=R(11);
    if(!call(s,ram,R(13),0x0c07d012))return 0;
    push(s,ram,R(14));R(7)=0;R(5)=word(ram,0x0c07d0e0);R(4)=word(ram,0x0c07d0de);R(6)=R(11);
    if(!call(s,ram,R(13),0x0c07d01e))return 0;
    R(0)=R(9);condition(s,R(0)==3);R(15)+=8;
    if(R(17)&1){
        R(2)=16;push(s,ram,R(2));R(7)=0;R(5)=word(ram,0x0c07d0e8);R(4)=word(ram,0x0c07d0e6);R(6)=R(12);
        if(!call(s,ram,R(13),0x0c07d034))return 0;
        R(3)=0;push(s,ram,R(3));R(7)=R(3);R(5)=word(ram,0x0c07d0e2);R(4)=word(ram,0x0c07d0da);R(6)=R(12);
        if(!call(s,ram,R(13),0x0c07d042))return 0;
        R(2)=0;push(s,ram,R(2));R(7)=R(2);R(5)=word(ram,0x0c07d0e4);R(4)=word(ram,0x0c07d0de);R(6)=R(12);
        if(!call(s,ram,R(13),0x0c07d050))return 0;
        R(15)+=12;goto restore;
    }
    R(9)--;R(5)=READ(0x0c07d0fc,4);R(3)=R(9);condition(s,R(3)==0);WRITE(R(15)+4,R(9),4);
    R(4)=READ(R(5)+((R(17)&1)?40:44),4);R(0)=50;R(9)=byte(ram,R(4)+R(0));R(0)=108;R(0)=READ(R(4)+R(0),4);
    condition(s,R(0)==6);R(9)&=255;if(R(17)&1)R(9)=9;
    R(2)=13;condition(s,(int32_t)R(9)>=(int32_t)R(2));if(R(17)&1)R(9)-=R(2);
    R(2)=READ(R(15)+4,4);R(1)=31;R(3)=R(2);R(2)<<=2;R(2)<<=2;shift(s,2);R(2)-=R(3);R(1)-=R(2);
    WRITE(R(15)+8,R(1),4);R(1)+=3;shift(s,1);WRITE(R(15),R(14),4);R(8)=word(ram,0x0c07d0ec);R(11)=word(ram,0x0c07d0ea);WRITE(R(15)+12,R(1),4);
    for(;;){
        R(3)=READ(R(15),4);condition(s,(int32_t)R(3)>=(int32_t)R(10));if(R(17)&1)break;
        R(2)=READ(R(15)+12,4);R(6)=R(12);R(5)=R(11);R(7)=0;R(2)|=R(8);WRITE(R(15)+16,R(2),4);push(s,ram,R(14));R(4)=R(2);
        if(!call(s,ram,R(13),0x0c07d0b0))return 0;
        R(15)+=4;R(3)=READ(R(15),4);R(11)++;R(3)++;WRITE(R(15),R(3),4);R(2)=word(ram,0x0c07d0ee);R(8)+=R(2);
    }
    R(1)=R(9);R(1)<<=2;shift(s,1);R(2)=word(ram,0x0c07d0f0);R(3)=R(9);R(1)+=R(3);R(1)+=R(2);WRITE(R(15),R(1),4);R(11)=R(14);
    for(;;){
        condition(s,(int32_t)R(11)>=(int32_t)R(10));if(R(17)&1)break;
        R(0)=READ(0x0c07d208,4);R(8)=R(11);R(2)=R(11);shift(s,8);R(1)=R(11);R(3)=READ(R(15)+8,4);
        R(8)=word(ram,R(0)+R(8));R(0)=R(9);R(8)+=R(3);shift(s,8);shift(s,2);condition(s,R(0)==7);R(2)+=R(1);R(1)=7;R(2)+=5;R(2)<<=7;R(8)|=R(2);
        if(R(17)&1){R(0)=R(11);condition(s,R(0)==5);if(R(17)&1){R(7)=0;push(s,ram,R(14));R(5)=word(ram,0x0c07d1fc);R(6)=R(12);goto special_icon;}}
        R(0)=R(9);condition(s,R(0)==10);
        if(R(17)&1){R(0)=R(11);condition(s,R(0)==6);if(R(17)&1){R(7)=0;push(s,ram,R(14));R(5)=word(ram,0x0c07d1fe);R(6)=R(12);goto special_icon;}}
        R(0)=R(9);condition(s,R(0)==8);
        if(R(17)&1){R(0)=R(11);condition(s,R(0)==6);if(R(17)&1){R(6)=R(12);push(s,ram,R(14));R(5)=word(ram,0x0c07d200);R(7)=0;goto special_icon;}}
        push(s,ram,R(14));R(7)=0;R(5)=READ(R(15)+4,4);R(6)=R(12);R(5)+=R(11);R(4)=R(8);
        if(!call(s,ram,R(13),0x0c07d174))return 0;
        R(0)=R(11);condition(s,R(0)==2);R(15)+=4;
        if(R(17)&1){
            R(2)=READ(R(15),4);R(0)=R(9);condition(s,R(0)==9);R(2)++;WRITE(R(15),R(2),4);R(8)+=8;
            if(!(R(17)&1)){
                R(5)=R(11);R(5)+=R(2);R(6)=R(12);push(s,ram,R(14));R(7)=0;R(4)=R(8);
                if(!call(s,ram,R(13),0x0c07d198))return 0;R(15)+=4;
            }
        }
        goto next_icon;
special_icon:
        R(4)=R(8);if(!call(s,ram,R(13),0x0c07d162))return 0;R(15)+=4;
next_icon:
        R(11)++;
    }
    R(12)=READ(R(15)+4,4);R(7)=0;R(5)=READ(0x0c07d20c,4);R(4)=R(12);R(0)=R(12);shift(s,4);R(0)<<=2;R(4)++;
    R(3)=word(ram,R(5)+R(0));R(0)=R(4);shift(s,0);R(3)&=65535;WRITE(R(15),R(3),4);
    R(2)=word(ram,R(5)+R(0));R(0)=R(12);R(0)<<=2;shift(s,0);R(2)&=65535;WRITE(R(15)+8,R(2),4);
    R(5)=READ(0x0c07d210,4);R(6)=READ(R(5)+R(0),4);R(0)=R(4);R(0)<<=2;R(1)=READ(R(5)+R(0),4);WRITE(R(15)+4,R(1),4);
    push(s,ram,R(14));R(4)=word(ram,0x0c07d202);R(5)=READ(R(15)+4,4);if(!call(s,ram,R(13),0x0c07d1da))return 0;
    push(s,ram,R(14));R(7)=0;R(6)=READ(R(15)+12,4);R(4)=word(ram,0x0c07d204);R(5)=READ(R(15)+16,4);
    if(!call(s,ram,R(13),0x0c07d1e6))return 0;R(15)+=8;
restore:
    R(15)+=20;R(16)=pop(s,ram);for(unsigned n=8;n<=14;n++)R(n)=pop(s,ram);s->pc=R(16);return ram->oob==0;
}
