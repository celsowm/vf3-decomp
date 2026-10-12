/* Character selection, duplicate avoidance and paired unlock/list updates.
 * Register temporaries and stack words preserve the original callback ABI.
 * Development candidate: deliberately unlinked until the strip freeze closes. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
static void condition(vf3_matrix_state *s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static uint32_t byte(const vf3_ram_map *ram,uint32_t a){return (uint32_t)(int32_t)(int8_t)READ(a,1);}
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t v){R(15)-=4;WRITE(R(15),v,4);}
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static int call(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t target,uint32_t returned){R(16)=returned;return vf3_matrix_family(target,s,ram);}
static uint32_t shifted(uint32_t value,uint32_t count)
{
    if(count&0x80000000u){unsigned n=((~count)&31u)+1u;return n==32?0:value>>n;}
    return value<<(count&31u);
}

int vf3_selection_unlock_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    for(unsigned n=14;n>=8;n--)push(s,ram,R(n));
    push(s,ram,R(16));R(3)=READ(0x0c0c3330,4);R(10)=READ(0x0c0c332c,4);R(15)-=40;
    R(13)=READ(0x0c0c3328,4);WRITE(R(15)+28,R(3),4);R(3)=0x300;R(2)=READ(R(10),4);R(9)=READ(0x0c0c3334,4);
    condition(s,(R(2)&R(3))==0);R(14)=R(4);if(!(R(17)&1))goto done;
    R(0)=READ(0x0c0c333c,4);R(3)=READ(0x0c0c3338,4);R(1)=READ(R(0),4);
    condition(s,(R(1)&R(3))==0);if(!(R(17)&1))goto done;
    R(0)=READ(R(14),4);condition(s,(R(0)&10)==0);if(!(R(17)&1))goto done;
    if(!call(s,ram,0x0c0c394c,0x0c0c3256))return 0;
    R(0)=49;R(2)=byte(ram,R(14)+R(0));R(0)=52;R(2)&=255;WRITE(R(15)+16,R(2),4);
    R(3)=byte(ram,R(14)+R(0));R(0)=53;R(3)&=255;WRITE(R(15),R(3),4);
    R(4)=READ(0x0c0c3340,4);R(12)=byte(ram,R(14)+R(0));R(3)=READ(R(4)+20,4);R(11)=READ(R(4)+16,4);WRITE(R(15)+20,R(3),4);
    R(0)=byte(ram,R(14)+4);condition(s,R(0)==0);R(12)&=255;
    if(!(R(17)&1)){R(4)=R(11);R(11)=READ(R(15)+20,4);WRITE(R(15)+20,R(4),4);}
    R(0)=125;R(5)=byte(ram,R(10)+R(0));R(0)=0x13c;R(5)&=255;R(4)=READ(R(10)+R(0),4);R(0)=R(5);
    condition(s,R(0)==1);
    if(R(17)&1){R(2)=16;condition(s,(R(4)&R(2))==0);if(!(R(17)&1))goto history_shift;}
    else {condition(s,R(0)==2);if(R(17)&1){R(1)=32;condition(s,(R(4)&R(1))==0);if(!(R(17)&1))goto history_shift;}else condition(s,R(0)==3);}
    goto history_ready;
history_shift:
    R(0)=0x3c6;
    for(unsigned n=0;n<7;n++){
        if(n&1){R(2)=byte(ram,R(13)+R(0));R(0)++;WRITE(R(13)+R(0),R(2),1);}
        else {R(3)=byte(ram,R(13)+R(0));R(0)++;WRITE(R(13)+R(0),R(3),1);}
        if(n<6)R(0)-=2;
    }
    R(0)=97;R(2)=byte(ram,R(11)+R(0));R(0)=0x3c0;WRITE(R(13)+R(0),R(2),1);
history_ready:
    R(3)=READ(0x0c0c3344,4);R(4)=R(11);if(!call(s,ram,R(3),0x0c0c32f2))return 0;
    R(2)=0x522;R(4)=READ(R(13)+44,4);condition(s,(int32_t)R(4)>(int32_t)R(2));R(8)=0;
    if(R(17)&1)goto resolve_character;
    /* Four directional inputs advance the two-bank, six-slot cursor. */
    R(0)=READ(R(15)+16,4);condition(s,(R(0)&32)==0);
    if(!(R(17)&1)){
        R(3)=READ(R(15),4);R(0)=108;R(1)=1;R(3)--;R(3)&=R(1);WRITE(R(15),R(3),4);
        R(0)=READ(R(14)+R(0),4);condition(s,R(0)==1);
        if(R(17)&1){R(0)=108;R(1)=2;WRITE(R(14)+R(0),R(1),4);}
        else {R(0)=108;WRITE(R(14)+R(0),R(8),4);}
    }
    R(0)=READ(R(15)+16,4);condition(s,(R(0)&16)==0);
    if(!(R(17)&1)){R(2)=READ(R(15),4);R(3)=1;R(0)=108;R(2)++;R(2)&=R(3);WRITE(R(15),R(2),4);WRITE(R(14)+R(0),R(3),4);}
    R(0)=READ(R(15)+16,4);condition(s,(R(0)&64)==0);
    if(!(R(17)&1)){
        R(2)=5;R(12)++;condition(s,(int32_t)R(12)>(int32_t)R(2));R(0)=108;if(R(17)&1)R(12)=R(8);
        R(0)=READ(R(14)+R(0),4);condition(s,R(0)==2);R(0)=108;
        if(R(17)&1){R(2)=3;WRITE(R(14)+R(0),R(2),4);}else WRITE(R(14)+R(0),R(8),4);
    }
    R(0)=READ(R(15)+16,4);condition(s,(R(0)&128)==0);
    if(!(R(17)&1)){
        R(12)--;condition(s,(int32_t)R(12)>=0);R(0)=108;if(!(R(17)&1))R(12)=5;
        R(0)=READ(R(14)+R(0),4);condition(s,R(0)==3);R(0)=108;
        if(R(17)&1){R(2)=4;WRITE(R(14)+R(0),R(2),4);}else WRITE(R(14)+R(0),R(8),4);
    }
    R(3)=READ(R(15),4);R(0)=52;WRITE(R(14)+R(0),R(3),1);R(0)=53;WRITE(R(14)+R(0),R(12),1);
resolve_character:
    if(!s->budget--)return 0;
    R(3)=READ(R(15),4);R(0)=READ(0x0c0c3418,4);R(2)=R(3);R(3)<<=3;R(3)-=R(2);R(3)+=R(12);R(12)=byte(ram,R(3)+R(0));
    R(0)=byte(ram,R(14)+4);condition(s,R(0)==0);R(4)=(R(17)&1)?0:1;
    R(2)=READ(0x0c0c341c,4);if(!call(s,ram,R(2),0x0c0c33d2))return 0;
    R(4)=R(0);R(0)=108;R(0)=READ(R(14)+R(0),4);condition(s,R(0)==4);
    if(R(17)&1){R(0)=READ(R(4)+8,4);condition(s,(R(0)&8)==0);if(!(R(17)&1)){R(0)=108;R(3)=5;WRITE(R(14)+R(0),R(3),4);}}
    R(0)=97;WRITE(R(11)+R(0),R(12),1);R(0)=byte(ram,R(14)+4);condition(s,R(0)==0);if(!(R(17)&1))R(12)+=13;
    R(0)=0xe8;R(4)=byte(ram,R(10)+R(0));R(0)=R(4)&255;condition(s,R(0)==3);R(4)=R(0);
    if(R(17)&1){
        R(0)=byte(ram,R(14)+4);condition(s,R(0)==0);
        if(R(17)&1){R(2)=READ(R(15)+20,4);R(0)=96;R(3)=byte(ram,R(2)+R(0))&255;condition(s,R(3)==R(12));if(R(17)&1)R(12)+=13;}
        else {R(3)=READ(R(15)+20,4);R(0)=96;R(2)=byte(ram,R(3)+R(0))&255;condition(s,R(2)==R(12));if(R(17)&1)R(12)-=13;}
    }
    R(4)=READ(R(13)+8,4);R(2)=4;condition(s,(R(4)&R(2))==0);
    if(!(R(17)&1)){
        R(0)=byte(ram,R(14)+4);R(4)=READ(0x0c0c351c,4);R(6)=R(0);R(0)=97;R(7)=byte(ram,R(11)+R(0));R(0)+=55;R(6)&=255;
        R(5)=READ(R(10)+R(0),4);R(7)&=255;R(7)=0-R(7);condition(s,R(6)==0);R(4)=shifted(R(4),R(7));R(4)&=R(5);
        if(R(17)&1){condition(s,R(4)==0);if(!(R(17)&1)){R(3)=13;condition(s,R(12)>=R(3));if(!(R(17)&1))R(12)+=13;}}
        else {condition(s,R(4)==0);if(!(R(17)&1)){R(3)=13;condition(s,R(12)>=R(3));if(R(17)&1)R(12)-=13;}}
    }
    R(0)=50;R(4)=byte(ram,R(14)+R(0))&255;condition(s,R(12)==R(4));
    if(R(17)&1){R(0)=108;R(0)=READ(R(14)+R(0),4);condition(s,R(0)==5);if(!(R(17)&1))goto choice_ready;}
    /* Publish a changed choice and reset its animation/confirmation fields. */
    R(0)=51;WRITE(R(14)+R(0),R(4),1);R(0)=56;R(2)=byte(ram,R(14)+R(0));R(3)=1;R(2)|=R(3);WRITE(R(14)+R(0),R(2),1);
    static const unsigned reset_offsets[]={76,74,68,70,72};
    for(unsigned n=0;n<5;n++){R(0)=reset_offsets[n];WRITE(R(14)+R(0),R(8),2);}
    R(0)=78;R(2)=0x7000;WRITE(R(14)+R(0),R(2),2);R(0)=58;WRITE(R(14)+R(0),R(3),1);
    R(0)=54;R(2)=byte(ram,R(14)+R(0));condition(s,R(2)==0);R(4)=R(12);
    if(!call(s,ram,0x0c0c396c,0x0c0c34b4))return 0;
    R(12)=R(0);R(0)=50;WRITE(R(14)+R(0),R(12),1);R(0)=96;WRITE(R(11)+R(0),R(12),1);
    R(0)=108;R(0)=READ(R(14)+R(0),4);condition(s,R(0)==5);if(R(17)&1){R(0)=108;R(2)=6;WRITE(R(14)+R(0),R(2),4);}
    R(0)=54;R(3)=1;WRITE(R(14)+R(0),R(3),1);WRITE(R(14)+60,R(8),4);R(4)=R(11);
    if(!call(s,ram,0x0c0c3982,0x0c0c34d8))return 0;
    R(2)=READ(0x0c0c3520,4);R(4)=R(11);if(!call(s,ram,R(2),0x0c0c34de))return 0;
choice_ready:
    R(3)=0x522;R(4)=READ(R(13)+44,4);condition(s,(int32_t)R(4)>(int32_t)R(3));if(R(17)&1)goto done;
    R(0)=READ(R(15)+16,4);condition(s,(R(0)&15)==0);
    if(!(R(17)&1)){
        R(0)=108;R(0)=READ(R(14)+R(0),4);condition(s,R(0)==6);
        if(R(17)&1){
            R(0)=0x98;R(3)=READ(0x0c0c3524,4);R(4)=READ(R(10)+R(0),4);condition(s,(R(4)&R(3))==0);R(0)=byte(ram,R(14)+4);
            if(R(17)&1){R(5)=22;R(4)=9;}else {R(4)=22;R(5)=9;}
            condition(s,R(0)==0);R(12)=(R(17)&1)?R(4):R(5);R(0)=97;R(3)=9;WRITE(R(11)+R(0),R(3),1);
        }
        goto load_unlock_flags;
    }
    R(2)=READ(R(13)+44,4);R(1)=63;condition(s,(int32_t)R(2)>(int32_t)R(1));if(R(17)&1)goto done;
    R(0)=108;R(0)=READ(R(14)+R(0),4);condition(s,R(0)==6);
    if(R(17)&1){
        R(0)=0x98;R(3)=READ(0x0c0c3608,4);R(4)=READ(R(10)+R(0),4);condition(s,(R(4)&R(3))==0);R(0)=byte(ram,R(14)+4);
        if(R(17)&1){R(4)=22;R(5)=9;}else {R(5)=22;R(4)=9;}
        condition(s,R(0)==0);R(12)=(R(17)&1)?R(5):R(4);R(0)=97;R(3)=9;WRITE(R(11)+R(0),R(3),1);
    }
    R(7)=R(8);goto prepare_unlock;
load_unlock_flags:
    R(0)=0x138;R(7)=READ(R(10)+R(0),4);
prepare_unlock:
    if(!s->budget--)return 0;
    R(0)=0x98;R(3)=READ(R(10)+R(0),4);R(0)=97;WRITE(R(15)+8,R(3),4);
    R(2)=byte(ram,R(11)+R(0))&255;WRITE(R(15)+12,R(2),4);R(0)=byte(ram,R(14)+4);condition(s,R(0)==0);R(5)=(R(17)&1)?16:32;
    WRITE(R(15),R(12),4);R(0)=byte(ram,R(14)+4);condition(s,R(0)==0);
    if(R(17)&1){
        R(2)=0x415;R(2)+=R(13);WRITE(R(15)+36,R(2),4);R(3)=0x41a;R(4)=byte(ram,R(9));R(3)+=R(13);WRITE(R(15)+32,R(3),4);
        R(4)&=255;R(0)=byte(ram,R(9)+1);R(6)=R(0)&255;R(3)=13;
    }else {
        R(1)=0x41a;R(1)+=R(13);WRITE(R(15)+36,R(1),4);R(3)=0x415;R(0)=byte(ram,R(9)+1);R(3)+=R(13);WRITE(R(15)+32,R(3),4);
        R(3)=0u-13u;R(6)=byte(ram,R(9));R(4)=R(0)&255;R(6)&=255;
    }
    condition(s,(R(7)&R(5))==0);WRITE(R(15)+24,R(3),4);if(R(17)&1)goto unlock_ready;
    R(3)=READ(R(15)+12,4);R(5)=READ(0x0c0c360c,4);R(2)=READ(R(15)+8,4);R(3)=0-R(3);R(5)=shifted(R(5),R(3));
    condition(s,(R(2)&R(5))==0);if(!(R(17)&1))goto unlock_ready;
    R(7)=READ(R(13)+8,4);R(3)=4;condition(s,(R(7)&R(3))==0);
    if(R(17)&1){
        R(0)=0xe8;R(0)=byte(ram,R(10)+R(0))&255;condition(s,R(0)==3);
        if(R(17)&1){R(4)=READ(R(15)+20,4);R(0)=97;R(3)=READ(R(15)+12,4);R(4)=byte(ram,R(4)+R(0))&255;condition(s,R(3)==R(4));if(R(17)&1)goto unlock_ready;}
        goto publish_unlock;
    }
    R(0)=0xe8;R(0)=byte(ram,R(10)+R(0))&255;condition(s,R(0)==3);
    if(R(17)&1){
        condition(s,R(6)==0);R(7)=R(8);
        if(!(R(17)&1)){
            /* The peer's inclusive search compares base characters. */
            do {
                if(!s->budget--)return 0;
                R(0)=READ(R(15)+32,4);R(1)=13;R(3)=byte(ram,R(7)+R(0))&255;condition(s,R(3)>=R(1));WRITE(R(15)+4,R(3),4);
                if(R(17)&1){R(0)=READ(R(15)+4,4);R(0)-=13;WRITE(R(15)+4,R(0),4);}
                R(1)=READ(R(15)+4,4);R(3)=READ(R(15)+12,4);condition(s,R(1)==R(3));if(R(17)&1)goto remap_unlock;
                R(7)++;condition(s,R(7)>R(6));
            }while(!(R(17)&1));
        }
    }
    /* The current player's search covers exactly its published count. */
    R(6)=R(8);
    for(;;){
        condition(s,R(4)==0);if(R(17)&1)break;
        if(!s->budget--)return 0;
        R(0)=READ(R(15)+36,4);R(7)=byte(ram,R(6)+R(0))&255;condition(s,R(7)==R(12));if(R(17)&1)goto remap_unlock;
        R(6)++;R(4)--;
    }
publish_unlock:
    R(2)=READ(R(15)+8,4);R(0)=54;R(5)|=R(2);R(2)=1;WRITE(R(15)+8,R(5),4);R(3)=READ(R(15)+24,4);R(3)+=R(12);WRITE(R(15),R(3),4);
    R(3)=R(2);WRITE(R(14)+R(0),R(2),1);R(0)=58;WRITE(R(14)+R(0),R(3),1);
remap_unlock:
    R(4)=READ(R(15),4);if(!call(s,ram,0x0c0c396c,0x0c0c3674))return 0;
    R(3)=R(0);WRITE(R(15),R(0),4);R(0)=96;WRITE(R(11)+R(0),R(3),1);R(0)=50;WRITE(R(14)+R(0),R(3),1);
    R(0)=0x98;R(2)=READ(R(15)+8,4);WRITE(R(10)+R(0),R(2),4);
unlock_ready:
    R(1)=0x461;R(3)=READ(R(15)+12,4);R(1)+=R(13);R(1)+=R(3);R(2)=byte(ram,R(1));R(2)++;WRITE(R(1),R(2),1);
    R(0)=READ(R(13)+8,4);condition(s,(R(0)&4)==0);if(R(17)&1)goto unpaired_choice;
    R(0)=0x413;R(3)=byte(ram,R(13)+R(0));WRITE(R(15)+24,R(3),4);R(0)=byte(ram,R(14)+4);condition(s,R(0)==0);
    if(R(17)&1){WRITE(R(15)+8,R(9),4);R(3)=0x415;}
    else {R(2)=R(9);R(2)++;WRITE(R(15)+8,R(2),4);R(3)=0x41a;}
    R(3)+=R(13);WRITE(R(15)+12,R(3),4);R(3)=READ(0x0c0c370c,4);R(4)=READ(R(15)+28,4);R(4)+=22;
    if(!call(s,ram,R(3),0x0c0c36c6))return 0;
    R(4)=R(0)&255;condition(s,R(4)==0);
    if(!(R(17)&1)){
        R(0)=byte(ram,R(14)+4);condition(s,R(0)==0);R(6)=R(9);R(6)+=(R(17)&1)?4:8;
        R(4)=READ(R(15),4);R(3)=13;condition(s,R(4)>=R(3));R(5)=READ(R(6),4);if(R(17)&1)R(4)-=R(3);
        R(2)=READ(0x0c0c3710,4);R(3)=0-R(4);R(2)=shifted(R(2),R(3));condition(s,(R(2)&R(5))==0);
        if(!(R(17)&1)){
            R(4)=READ(R(13)+44,4);R(3)=63;condition(s,(int32_t)R(4)>(int32_t)R(3));if(R(17)&1)goto done;
            goto next_unused_choice;
        }
        R(1)=READ(0x0c0c3830,4);R(4)=0-R(4);R(1)=shifted(R(1),R(4));R(5)|=R(1);WRITE(R(6),R(5),4);
    }
    /* First insertion may immediately publish when the round timer expires. */
    R(3)=READ(R(15)+8,4);R(1)=96;R(1)+=R(11);R(2)=byte(ram,R(3))&255;WRITE(R(15)+4,R(2),4);
    R(0)=READ(R(15)+12,4);R(3)=READ(R(15),4);WRITE(R(1),R(3),1);R(1)=50;R(1)+=R(14);WRITE(R(1),R(3),1);WRITE(R(2)+R(0),R(3),1);
    R(0)=108;R(0)=READ(R(14)+R(0),4);condition(s,R(0)==6);
    if(!(R(17)&1)){R(5)=R(11);R(4)=R(14);if(!call(s,ram,0x0c0c38c6,0x0c0c3746))return 0;}
    R(3)=READ(R(15)+4,4);R(3)++;WRITE(R(15)+4,R(3),4);R(2)=READ(R(15)+24,4);condition(s,R(3)>=R(2));if(R(17)&1)goto list_full;
    R(2)=READ(R(15)+4,4);R(3)=READ(R(15)+8,4);WRITE(R(3),R(2),1);R(3)=63;R(4)=READ(R(13)+44,4);condition(s,(int32_t)R(4)>(int32_t)R(3));if(R(17)&1)goto publish_list;
    R(0)=0x413;R(2)=byte(ram,R(13)+R(0));WRITE(R(15)+24,R(2),4);R(0)=byte(ram,R(14)+4);condition(s,R(0)==0);
    if(R(17)&1){WRITE(R(15)+8,R(9),4);R(3)=0x415;R(3)+=R(13);WRITE(R(15)+12,R(3),4);}
    else {R(3)=R(9);R(3)++;WRITE(R(15)+8,R(3),4);R(2)=0x41a;R(2)+=R(13);WRITE(R(15)+12,R(2),4);}
next_unused_choice:
    if(!s->budget--)return 0;
    R(3)=READ(0x0c0c3834,4);R(4)=READ(R(15)+28,4);R(4)+=22;if(!call(s,ram,R(3),0x0c0c378a))return 0;
    R(4)=R(0)&255;condition(s,R(4)==0);
    if(!(R(17)&1)){
        R(0)=byte(ram,R(14)+4);condition(s,R(0)==0);R(4)=R(9);R(4)+=(R(17)&1)?4:8;
        R(6)=READ(R(15),4);R(3)=13;condition(s,R(6)>=R(3));R(5)=READ(R(4),4);if(R(17)&1)R(6)-=R(3);
        R(7)=READ(0x0c0c3830,4);R(6)=0-R(6);R(7)=shifted(R(7),R(6));R(3)=R(7);condition(s,(R(3)&R(5))==0);
        if(!(R(17)&1)){
            R(0)=52;R(1)=byte(ram,R(14)+R(0));R(0)=53;R(3)=5;R(1)&=255;WRITE(R(15),R(1),4);R(12)=byte(ram,R(14)+R(0))&255;
            R(12)++;condition(s,(int32_t)R(12)>(int32_t)R(3));
            if(R(17)&1){R(1)=READ(R(15),4);R(2)=1;R(12)=R(8);R(1)++;R(1)&=R(2);WRITE(R(15),R(1),4);}
            R(3)=READ(R(15),4);R(0)=52;WRITE(R(14)+R(0),R(3),1);R(0)=53;WRITE(R(14)+R(0),R(12),1);goto resolve_character;
        }
        R(5)|=R(7);WRITE(R(4),R(5),4);
    }
    R(2)=READ(R(15)+8,4);R(1)=96;R(1)+=R(11);R(3)=byte(ram,R(2))&255;WRITE(R(15)+4,R(3),4);
    R(0)=READ(R(15)+12,4);R(2)=READ(R(15),4);WRITE(R(1),R(2),1);R(1)=50;R(1)+=R(14);WRITE(R(1),R(2),1);WRITE(R(3)+R(0),R(2),1);
    R(0)=108;R(0)=READ(R(14)+R(0),4);condition(s,R(0)==6);
    if(!(R(17)&1)){R(5)=R(11);R(4)=R(14);if(!call(s,ram,0x0c0c38c6,0x0c0c3812))return 0;}
    R(3)=READ(R(15)+4,4);R(3)++;WRITE(R(15)+4,R(3),4);R(2)=READ(R(15)+24,4);condition(s,R(3)>=R(2));if(R(17)&1)goto list_full;
    R(2)=READ(R(15)+4,4);R(3)=READ(R(15)+8,4);WRITE(R(3),R(2),1);goto load_unlock_flags;
list_full:
    R(0)=READ(R(14),4);R(0)|=8;WRITE(R(14),R(0),4);
publish_list:
    if(!call(s,ram,0x0c0c394c,0x0c0c3842))return 0;
    R(0)=byte(ram,R(14)+4);R(4)=0x415;R(0)&=255;R(3)=R(0);R(0)<<=2;R(4)+=R(13);R(0)+=R(3);R(4)=byte(ram,R(4)+R(0));R(0)=104;WRITE(R(14)+R(0),R(4),1);
    R(4)=R(11);if(!call(s,ram,0x0c0c3982,0x0c0c385a))return 0;
    R(2)=READ(0x0c0c3930,4);R(4)=R(11);if(!call(s,ram,R(2),0x0c0c3860))return 0;
    R(3)=READ(R(15),4);R(0)=51;WRITE(R(14)+R(0),R(3),1);goto done;
unpaired_choice:
    R(0)=R(12);condition(s,R(0)==9);
    if(!(R(17)&1)){R(0)=R(12);condition(s,R(0)==22);}
    if(R(17)&1){
        R(0)=0x98;R(3)=READ(0x0c0c3934,4);R(4)=READ(R(10)+R(0),4);condition(s,(R(4)&R(3))==0);R(0)=byte(ram,R(14)+4);
        if(R(17)&1){R(5)=22;R(4)=9;}else {R(4)=22;R(5)=9;}
        condition(s,R(0)==0);R(0)=50;R(6)=(R(17)&1)?R(4):R(5);WRITE(R(14)+R(0),R(6),1);
    }
    R(4)=R(11);if(!call(s,ram,0x0c0c3982,0x0c0c389c))return 0;
    R(2)=READ(0x0c0c3930,4);R(4)=R(11);if(!call(s,ram,R(2),0x0c0c38a2))return 0;
    R(0)=READ(R(14),4);R(0)|=8;WRITE(R(14),R(0),4);R(0)=51;R(2)=READ(0x0c0c3938,4);R(3)=READ(R(15),4);WRITE(R(14)+R(0),R(3),1);
    if(!call(s,ram,R(2),0x0c0c38b2))return 0;
done:
    R(15)+=40;R(16)=pop(s,ram);for(unsigned n=8;n<=14;n++)R(n)=pop(s,ram);
    s->pc=R(16);return ram->oob==0;
}
