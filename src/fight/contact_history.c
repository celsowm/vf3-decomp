/* Update the five-entry contact history from a motion/contact record.
 * Callable 0x0c0c0bf4; frozen inventory owner 0x8c0c0c04. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
static void push(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t v){R(15)-=4;WRITE(R(15),v,4);}
static uint32_t pop(vf3_matrix_state*s,const vf3_ram_map*ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static uint32_t word(const vf3_ram_map*ram,uint32_t a){return (uint32_t)(int32_t)(int16_t)READ(a,2);}
static uint32_t byte(const vf3_ram_map*ram,uint32_t a){return (uint32_t)(int32_t)(int8_t)READ(a,1);}
static void condition(vf3_matrix_state*s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static uint32_t shift(uint32_t v,uint32_t amount)
{int32_t n=(int32_t)amount;return n>=0?v<<(n&31):((n&31)?(uint32_t)((int32_t)v>>((-n)&31)):((int32_t)v<0?0xffffffffu:0));}
static int call(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t entry,uint32_t ret)
{R(16)=ret;return vf3_matrix_family(entry,s,ram)&&s->pc==R(16);}
/* Search 128 rows of five character bytes for the retained actor history. */
static int find_history(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    push(s,ram,R(14));R(14)=0;push(s,ram,R(13));push(s,ram,R(12));R(12)=R(14);push(s,ram,R(11));push(s,ram,R(16));
    R(15)-=12;WRITE(R(15)+4,R(4),4);WRITE(R(15),R(5),4);R(13)=R(14);
    for(;;){
        if(!s->budget--)return 0;
        R(0)=READ(R(15)+4,4);R(4)=R(12);R(3)=READ(R(15),4);R(4)<<=2;R(11)=R(0);R(4)<<=2;R(11)+=16;
        R(2)=READ(R(3)+4,4);condition(s,R(4)&0x80000000u);R(4)<<=1;R(11)+=R(13);R(4)+=R(2);R(11)=byte(ram,R(11));WRITE(R(15)+8,R(4),4);
        R(3)=READ(0x0c0c0f5c,4);R(4)+=R(13);if(!call(s,ram,R(3),0x0c0c0ef0))return 0;
        R(6)=R(0)&255;condition(s,R(6)==R(11));R(5)=1;R(7)=(R(17)&1)?R(14):R(5);
        R(2)=word(ram,0x0c0c0f56);condition(s,R(11)==R(2));R(4)=(R(17)&1)?R(14):R(5);
        R(3)=word(ram,0x0c0c0f56);condition(s,R(6)==R(3));R(6)=(R(17)&1)?R(14):R(5);condition(s,R(7)==0);
        if(R(17)&1){
            condition(s,R(4)==0);if(R(17)&1){R(0)=0;break;}
            R(3)=4;R(4)=R(13);condition(s,(int32_t)R(4)>=(int32_t)R(3));R(13)++;
            if(!(R(17)&1))continue;
            R(0)=0;break;
        }
        condition(s,R(4)==0);if(!(R(17)&1))condition(s,R(6)==0);
        if(R(17)&1){R(0)=1;break;}
        R(2)=127;condition(s,(int32_t)R(12)>=(int32_t)R(2));
        if(R(17)&1){R(0)=R(12)-127;break;}
        R(12)++;R(13)=R(14);
    }
    R(15)+=12;R(16)=pop(s,ram);R(11)=pop(s,ram);R(12)=pop(s,ram);R(13)=pop(s,ram);s->pc=R(16);R(14)=pop(s,ram);return ram->oob==0;
}
/* Select a fallback row from character lengths, retaining the original tie rules. */
static int fallback_history(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    push(s,ram,R(14));R(3)=2;for(unsigned i=13;i>=8;i--)push(s,ram,R(i));push(s,ram,R(16));push(s,ram,R(19));
    R(15)-=12;WRITE(R(15)+4,R(4),4);R(4)=R(5);WRITE(R(15),R(5),4);R(4)=READ(R(4)+44,4);R(11)=READ(0x0c0c1090,4);R(4)=READ(R(4),4);condition(s,(R(4)&R(3))==0);
    if(R(17)&1)R(0)=0;
    else {
        R(3)=4;R(9)=word(ram,0x0c0c1088);R(14)=0;WRITE(R(15)+8,R(3),4);R(12)=word(ram,0x0c0c108a);
        for(;;){
            R(13)=0;
            for(;;){
                if(!s->budget--)return 0;
                R(8)=READ(R(15),4);R(4)=R(14);R(4)<<=2;R(3)=READ(0x0c0c1094,4);R(8)=READ(R(8)+4,4);R(4)<<=2;
                condition(s,R(4)&0x80000000u);R(4)<<=1;R(8)+=R(4);R(4)=R(8)+R(13);
                if(!call(s,ram,R(3),0x0c0c0fa8))return 0;
                R(2)=word(ram,0x0c0c1088);R(4)=R(0)&255;condition(s,R(4)==R(2));
                if(R(17)&1){
                    R(3)=1;condition(s,(int32_t)R(13)>(int32_t)R(3));if(!(R(17)&1))goto selected;
                    R(3)=READ(R(15)+8,4);condition(s,(int32_t)R(13)>=(int32_t)R(3));
                    if(!(R(17)&1)){WRITE(R(15)+8,R(13),4);R(12)=R(14);break;}
                    goto compare_length;
                }
                R(2)=READ(0x0c0c1094,4);R(4)=R(8)+5+R(13);if(!call(s,ram,R(2),0x0c0c0fca))return 0;
                R(10)=R(0)&255;condition(s,R(10)==0);if(R(17)&1)goto selected;
                R(2)=4;R(4)=R(13);condition(s,(int32_t)R(4)>=(int32_t)R(2));R(13)++;
                if(!(R(17)&1))continue;
compare_length:
                condition(s,(int32_t)R(10)>=(int32_t)R(9));if(!(R(17)&1)){R(9)=R(10);R(12)=R(14);}break;
            }
            R(3)=127;R(4)=R(14);condition(s,(int32_t)R(4)>=(int32_t)R(3));R(14)++;if(R(17)&1)break;
        }
        R(3)=word(ram,0x0c0c108a);condition(s,R(12)==R(3));R(14)=R(12);
        if(R(17)&1){
            R(0)=word(ram,0x0c0c108c);R(4)=READ(R(11)+R(0),4);R(0)+=4;R(3)=READ(R(11)+R(0),4);R(0)+=4;R(2)=word(ram,R(11)+R(0));R(0)-=8;
            R(19)=R(4)*R(3);R(4)=R(19)+R(2);WRITE(R(11)+R(0),R(4),4);R(4)>>=16;R(14)=word(ram,0x0c0c108e);R(4)=(uint32_t)(int32_t)(int16_t)R(4);
            R(3)=READ(0x0c0c1098,4);R(0)-=48;R(14)&=R(4);R(1)=R(14);if(!call(s,ram,R(3),0x0c0c1022))return 0;R(14)=R(0);
        }
selected:
        R(0)=R(14);
    }
    R(15)+=12;R(19)=pop(s,ram);R(16)=pop(s,ram);for(unsigned i=8;i<=13;i++)R(i)=pop(s,ram);s->pc=R(16);R(14)=pop(s,ram);return ram->oob==0;
}
int vf3_contact_history_helpers_c(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram)
{return entry==0x0c0c0eba?find_history(s,ram):fallback_history(s,ram);}
int vf3_contact_history_c(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    int clear=0;
    push(s,ram,R(14));R(14)=R(4);push(s,ram,R(13));R(13)=R(7);
    push(s,ram,R(12));push(s,ram,R(11));push(s,ram,R(10));R(4)=READ(0x0c0c0cd4,4);push(s,ram,R(16));
    R(3)=READ(0x0c0c0cd8,4);R(7)=READ(R(4),4);R(15)-=20;condition(s,(R(7)&R(3))==0);
    if(!(R(17)&1)){
        R(2)=READ(R(4)+4,4);R(3)=READ(0x0c0c0cdc,4);condition(s,(R(2)&R(3))==0);
        if(!(R(17)&1)){
            R(3)=READ(R(13)+12,4);R(11)=word(ram,0x0c0c0cce);condition(s,(R(3)&R(11))==0);R(12)=0;
            if(!(R(17)&1))clear=1;
            else {
                R(3)=READ(0x0c0c0ce4,4);R(2)=READ(R(13)+12,4);R(10)=READ(0x0c0c0ce0,4);R(4)=word(ram,0x0c0c0cd0);
                condition(s,(R(2)&R(3))==0);R(7)=1;
                if(!(R(17)&1)){
                    R(2)=READ(R(13)+40,4);condition(s,(R(2)&R(10))==0);R(12)=R(4);if(!(R(17)&1))R(12)=R(11);
                    goto upper_bits;
                }
                R(1)=READ(R(13)+12,4);condition(s,(R(1)&R(10))==0);
                if(!(R(17)&1)){R(12)=READ(0x0c0c0e50,4);goto upper_bits;}
                R(0)=READ(R(13)+12,4);condition(s,(R(0)&22)==0);
                if(!(R(17)&1)){
                    R(3)=READ(R(13)+28,4);R(2)=word(ram,0x0c0c0cd2);condition(s,R(3)==R(2));
                    if(R(17)&1){
                        R(0)=READ(R(13)+12,4);condition(s,(R(0)&2)==0);
                        if(!(R(17)&1)){
                            R(2)=READ(R(13)+20,4);condition(s,R(2)==0);
                            if(!(R(17)&1)){R(2)=READ(R(13)+12,4);R(3)=word(ram,0x0c0c0e44);R(2)|=R(3);WRITE(R(13)+12,R(2),4);}
                        }
                    }else {
                        R(0)=READ(R(13)+12,4);condition(s,(R(0)&20)==0);
                        if(R(17)&1){
                            R(5)=READ(R(13)+20,4);R(3)=R(14)+44;R(5)<<=2;R(5)+=R(3);R(5)=READ(R(5),4);condition(s,R(5)==0);
                            if(!(R(17)&1)){
                                R(2)=READ(R(13)+40,4);condition(s,(R(2)&R(10))==0);R(0)=97;if(!(R(17)&1))R(4)=R(11);
                                R(5)=byte(ram,R(6)+R(0));R(3)=31;R(2)=READ(R(13)+20,4);R(5)&=255;R(3)-=R(5);R(7)=shift(R(7),R(3));
                                R(3)=R(14)+44;R(2)<<=2;R(2)+=R(3);R(4)|=R(7);WRITE(R(2),R(4),4);
                            }
                            R(3)=READ(R(13)+24,4);R(0)=68;R(4)=word(ram,R(14)+R(0));WRITE(R(14)+R(0),R(3),2);
                            R(0)=72;R(2)=READ(R(13)+24,4);WRITE(R(14)+R(0),R(2),2);R(3)=READ(R(13)+20,4);condition(s,R(3)==0);
                            if(!(R(17)&1)){
                                R(3)=READ(R(13)+24,4);condition(s,(int32_t)R(3)>=(int32_t)R(4));
                                if(!(R(17)&1))clear=1;
                                else {R(3)=READ(R(13)+20,4);R(5)=R(14)+32;R(2)=READ(R(13)+24,4);condition(s,(R(3)&0x80000000u)!=0);R(3)<<=1;R(2)-=R(4);R(5)+=R(3);R(4)=R(2);WRITE(R(5),R(4),2);}
                            }
                        }else {
                            /* Commit one entry's character and packed contact flags. */
                            R(2)=R(14)+16;R(3)=READ(R(13)+20,4);R(1)=READ(R(13)+28,4);R(2)+=R(3);WRITE(R(2),R(1),1);
                            R(3)=word(ram,0x0c0c0e40);R(0)=word(ram,0x0c0c0e42);WRITE(R(5)+R(0),R(3),1);
                            R(0)=70;R(5)=READ(R(13)+24,4)+1;WRITE(R(14)+R(0),R(5),2);R(0)=64;R(3)=word(ram,0x0c0c0e44);R(5)=R(12);
                            R(2)=READ(R(13)+12,4)|R(3);WRITE(R(13)+12,R(2),4);R(2)=15;R(6)=READ(R(14)+R(0),4);R(3)=0xffffffcfu;WRITE(R(14)+R(0),R(12),4);
                            R(2)&=R(6);R(1)=word(ram,0x0c0c0e46);R(5)|=R(2);R(2)=96;R(2)&=R(6);condition(s,R(2)&1);R(2)=(uint32_t)((int32_t)R(2)>>1);
                            R(5)&=R(3);R(5)|=R(2);R(5)&=R(1);R(2)=word(ram,0x0c0c0e48);R(3)=word(ram,0x0c0c0e4a);R(2)&=R(6);
                            condition(s,R(2)&1);R(2)=(uint32_t)((int32_t)R(2)>>1);condition(s,R(2)&1);R(2)=(uint32_t)((int32_t)R(2)>>1);
                            condition(s,(R(6)&R(4))==0);R(5)|=R(2);R(5)&=R(3);if(!(R(17)&1)){R(0)=word(ram,0x0c0c0e4c);R(5)|=R(0);}
                            R(3)=READ(R(13)+20,4);R(2)=R(14)+22;condition(s,R(3)&0x80000000u);R(3)<<=1;R(3)+=R(2);WRITE(R(3),R(5),2);
                            R(3)=READ(R(13)+20,4);condition(s,(int32_t)R(3)>=(int32_t)R(7));
                            if(R(17)&1){
                                R(0)=READ(R(13)+12,4);R(5)=R(13);R(0)|=128;WRITE(R(13)+12,R(0),4);R(4)=R(14);
                                if(!call(s,ram,0x0c0c0eba,0x0c0c0d5c))return 0;
                                R(4)=R(0);condition(s,R(4)==0);
                                if(R(17)&1){R(5)=R(13);R(4)=R(14);if(!call(s,ram,0x0c0c0f60,0x0c0c0d68))return 0;}
                            }
                            R(5)=READ(R(13)+20,4);R(4)=4;R(2)=R(5);condition(s,(int32_t)R(5)>=(int32_t)R(4));R(2)++;WRITE(R(13)+20,R(2),4);
                            if(R(17)&1){
                                R(0)=word(ram,R(14)+22);R(3)=word(ram,0x0c0c0e4e);R(5)=R(0);condition(s,(R(5)&R(3))==0);
                                if(!(R(17)&1))clear=1;
                                else {
                                    /* Drop the oldest entry by shifting the retained history. */
                                    WRITE(R(13)+20,R(4),4);R(4)=R(14)+16;R(5)=R(14)+22;
                                    R(0)=byte(ram,R(4)+1);R(6)=R(0);R(0)=byte(ram,R(4)+2);WRITE(R(15)+12,R(0),4);
                                    R(0)=byte(ram,R(4)+3);WRITE(R(15)+16,R(0),4);R(0)=byte(ram,R(4)+4);WRITE(R(15)+4,R(0),4);
                                    R(0)=word(ram,R(5)+2);WRITE(R(15)+8,R(0),4);R(0)=word(ram,R(5)+4);WRITE(R(15),R(0),4);R(0)=word(ram,R(5)+6);R(7)=R(0);R(0)=word(ram,R(5)+8);
                                    WRITE(R(4),R(6),1);R(3)=READ(R(15)+12,4);R(5)=R(0);R(0)=17;WRITE(R(14)+R(0),R(3),1);
                                    R(0)=18;R(2)=READ(R(15)+16,4);WRITE(R(14)+R(0),R(2),1);R(0)=19;R(3)=READ(R(15)+4,4);WRITE(R(14)+R(0),R(3),1);
                                    R(0)=word(ram,R(15)+8);WRITE(R(14)+22,R(0),2);R(4)=R(14);R(0)=READ(R(15),4);R(4)+=44;WRITE(R(14)+24,R(0),2);
                                    R(0)=R(7);WRITE(R(14)+26,R(0),2);R(0)=R(5);WRITE(R(14)+28,R(0),2);
                                    R(0)=36;R(3)=word(ram,R(14)+R(0));R(0)=38;WRITE(R(15),R(3),4);R(2)=word(ram,R(14)+R(0));R(0)=40;WRITE(R(15)+8,R(2),4);
                                    R(3)=word(ram,R(14)+R(0));R(0)=34;WRITE(R(15)+4,R(3),4);R(3)=READ(R(15),4);R(6)=READ(R(4)+12,4);R(7)=READ(R(4)+8,4);R(5)=READ(R(4)+4,4);R(4)=READ(R(4)+16,4);
                                    WRITE(R(14)+R(0),R(3),2);R(0)=36;R(2)=READ(R(15)+8,4);WRITE(R(14)+R(0),R(2),2);R(0)=38;R(3)=READ(R(15)+4,4);WRITE(R(14)+R(0),R(3),2);
                                    WRITE(R(14)+44,R(5),4);R(3)=0xffffffffu;WRITE(R(14)+48,R(7),4);R(0)=20;WRITE(R(14)+52,R(6),4);WRITE(R(14)+56,R(4),4);WRITE(R(14)+R(0),R(3),1);
                                    R(0)=R(12);WRITE(R(14)+30,R(0),2);R(0)=40;WRITE(R(14)+R(0),R(12),2);R(0)=42;WRITE(R(14)+R(0),R(12),2);WRITE(R(14)+60,R(12),4);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    goto finish;
upper_bits:
    R(4)=READ(R(13)+20,4);R(0)=97;R(3)=R(14)+44;R(4)<<=2;R(4)+=R(3);R(3)=31;WRITE(R(15),R(4),4);
    R(5)=byte(ram,R(6)+R(0));R(2)=READ(0x0c0c0f58,4);R(5)&=255;R(4)=READ(R(4),4);R(3)-=R(5);R(7)=shift(R(7),R(3));R(3)=READ(R(15),4);
    R(12)|=R(7);R(12)<<=16;R(4)&=65535;R(12)&=R(2);R(4)|=R(12);WRITE(R(3),R(4),4);
finish:
    R(15)+=20;
    if(clear){R(2)=READ(R(13)+12,4);R(16)=pop(s,ram);R(0)=64;R(3)=word(ram,0x0c0c0f54);R(5)=R(13);R(4)=R(14);R(2)&=R(3);WRITE(R(13)+12,R(2),4);WRITE(R(14)+R(0),R(12),4);}
    else R(16)=pop(s,ram);
    for(unsigned i=10;i<=14;i++)R(i)=pop(s,ram);
    if(clear)return vf3_matrix_family(0x0c0c103c,s,ram)&&s->pc==R(16)&&ram->oob==0;
    s->pc=R(16);return ram->oob==0;
}
