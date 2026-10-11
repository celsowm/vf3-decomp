/* Initialize enabled scene contact records and their eight box corners.
 * Callable 0x0c0a07e4; frozen owner 0x8c0a07fa. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#define R(n) s->v[(n)]
#define F(n) s->v[21+(n)]
#define READ(a,n) vf3_matrix_read(ram,(a),(n))
#define WRITE(a,v,n) vf3_matrix_write(ram,(a),(v),(n))
static void push(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t v){R(15)-=4;WRITE(R(15),v,4);}
static uint32_t pop(vf3_matrix_state*s,const vf3_ram_map*ram){uint32_t v=READ(R(15),4);R(15)+=4;return v;}
static uint32_t word(const vf3_ram_map*ram,uint32_t a){return (uint32_t)(int32_t)(int16_t)READ(a,2);}
static void condition(vf3_matrix_state*s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static void op(vf3_matrix_state*s,unsigned d,unsigned f,char c){F(d)=vf3_fpu_binary(F(d),F(f),R(18),c);}
static int call(vf3_matrix_state*s,const vf3_ram_map*ram,unsigned r,uint32_t pool,uint32_t ret)
{R(r)=READ(pool,4);R(16)=ret;return vf3_matrix_family(R(r),s,ram)&&s->pc==R(16);}
static int random_call(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t ret)
{R(16)=ret;return vf3_matrix_family(R(12),s,ram)&&s->pc==R(16);}
int vf3_contact_init_c(vf3_matrix_state*s,const vf3_ram_map*ram)
{
    if(!vf3_fpu_supported(R(18))||(R(18)&0x100000u))return 0;
    for(unsigned i=14;i>=8;i--)push(s,ram,R(i));
    for(unsigned i=15;i>=12;i--)push(s,ram,F(i));
    push(s,ram,R(16));R(15)-=24;WRITE(R(15),R(4),4);
    R(3)=READ(0x0c0a0848,4);WRITE(R(15)+12,R(3),4);R(4)=0;
    if(!call(s,ram,3,0x0c0a0854,0x0c0a080a))return 0;
    R(0)=word(ram,0x0c0a0840);R(2)=READ(R(15)+12,4);R(4)=READ(0x0c0a0858,4);
    R(3)=(uint32_t)(int32_t)(int8_t)READ(R(2)+R(0),1);condition(s,R(3)==0);R(0)=72;
    R(5)=READ(R(4)+((R(17)&1)?20:16),4);R(6)=READ(R(4)+((R(17)&1)?16:20),4);
    R(3)=word(ram,0x0c0a0842);R(7)=READ(R(6)+R(0),4);condition(s,(R(7)&R(3))==0);
    if(R(17)&1){R(0)=word(ram,0x0c0a0844);R(6)=word(ram,R(5)+R(0));R(0)=word(ram,R(5)+30);R(6)&=65535;R(10)=(R(0)&65535)+R(6);}
    else {R(0)=word(ram,R(6)+30);R(10)=R(0)&65535;}
    R(0)=68;R(2)=word(ram,0x0c0a09d8);R(4)=READ(R(4)+R(0),4);R(9)=18;R(3)=READ(R(15),4);
    R(0)=word(ram,0x0c0a09d6);R(2)+=R(3);R(11)=READ(0x0c0a09ec,4);R(13)=READ(R(4)+R(0),4);
    R(8)=READ(0x0c0a09f0,4);WRITE(R(15)+8,R(2),4);
    do{
        if(!s->budget--)return 0;
        R(0)=4;F(15)=READ(R(8)+R(0),4);R(0)=(uint32_t)(int32_t)(int8_t)READ(R(8)+8,1);condition(s,R(0)==1);
        if(R(17)&1){
            R(14)=word(ram,0x0c0a09da);WRITE(R(15),R(13),4);R(5)=READ(R(15)+8,4);R(14)+=R(13);R(4)=R(14)+16;
            if(!call(s,ram,3,0x0c0a09f4,0x0c0a0894))return 0;
            R(0)=0x0c0a09f8;F(14)=0x3f800000;F(5)=READ(R(0),4);R(0)=0x0c0a09fc;F(4)=READ(R(0),4);
            R(0)=0x0c0a0a00;op(s,5,15,'*');F(6)=READ(R(0),4);op(s,4,15,'*');R(0)=0x0c0a0a04;op(s,6,15,'*');F(8)=READ(R(0),4);
            R(3)=READ(R(15)+12,4);R(0)=0x0c0a0a08;
            F(3)=F(5);F(5)=F(14);op(s,5,3,'/');F(3)=F(4);F(4)=F(14);op(s,4,3,'/');F(3)=F(6);F(6)=F(14);op(s,6,3,'/');
            F(11)=READ(R(0),4);R(0)=4;F(10)=READ(R(3),4)^0x80000000u;F(7)=0;F(9)=F(8);
            WRITE(R(14),F(11),4);WRITE(R(14)+4,F(5),4);R(0)=8;WRITE(R(14)+R(0),F(4),4);R(0)=12;F(6)^=0x80000000u;
            R(4)=(uint32_t)(int32_t)(int16_t)R(10);WRITE(R(14)+R(0),F(6),4);
            R(0)=104;WRITE(R(14)+R(0),F(7),4);R(0)=108;WRITE(R(14)+R(0),F(10),4);R(0)=112;WRITE(R(14)+R(0),F(7),4);
            R(0)=116;WRITE(R(14)+R(0),F(9),4);R(0)=120;WRITE(R(14)+R(0),F(9),4);
            R(0)=4;F(3)=READ(R(11),4);WRITE(R(15)+R(0),F(3),4);F(3)=READ(R(11)+R(0),4);R(0)=20;WRITE(R(15)+R(0),F(3),4);
            R(0)=8;F(13)=READ(R(11)+R(0),4);WRITE(R(15)+16,R(4),4);
            if(!call(s,ram,3,0x0c0a0a0c,0x0c0a090a))return 0;
            F(12)=F(0);R(4)=READ(R(15)+16,4);if(!call(s,ram,3,0x0c0a0a10,0x0c0a0912))return 0;
            R(0)=4;F(1)=F(12);F(3)=READ(R(15)+R(0),4);op(s,1,13,'*');F(2)=F(0);R(0)=92;op(s,2,3,'*');
            F(4)=F(0);op(s,4,13,'*');op(s,2,1,'-');WRITE(R(14)+R(0),F(2),4);
            R(0)=20;F(3)=READ(R(15)+R(0),4);R(0)=96;WRITE(R(14)+R(0),F(3),4);R(0)=4;F(3)=READ(R(15)+R(0),4);
            R(0)=100;op(s,12,3,'*');F(12)^=0x80000000u;op(s,12,4,'-');WRITE(R(14)+R(0),F(12),4);
            R(0)+=60;R(12)=READ(0x0c0a0a14,4);WRITE(R(14)+R(0),F(15),4);if(!random_call(s,ram,0x0c0a0946))return 0;
            /* Three random half-turn angles, followed by three random deltas. */
            for(unsigned k=0;k<3;k++){
                R(1)=word(ram,0x0c0a09deu+2*k);condition(s,(R(0)&0x80000000u)!=0);R(0)<<=1;
                R(3)=word(ram,0x0c0a09dc);R(1)+=R(14);R(0)+=R(3);WRITE(R(1),R(0),2);
                if(!random_call(s,ram,0x0c0a0954+14*k))return 0;
            }
            for(unsigned k=0;k<3;k++){
                R(1)=R(0);R(0)=24;if(!call(s,ram,3,0x0c0a0a18,0x0c0a0978+16*k))return 0;
                R(1)=word(ram,0x0c0a09e4+2*k);R(1)+=R(14);WRITE(R(1),R(0),2);
                if(k<2&&!random_call(s,ram,0x0c0a0980+16*k))return 0;
            }
            R(0)=0x0c0a0a1c;F(7)=READ(R(0),4);R(0)=0x0c0a0a20;F(6)=READ(R(0),4);R(0)=0x0c0a0a24;F(5)=READ(R(0),4);
            R(0)=80;F(4)=0;WRITE(R(14)+R(0),F(7),4);R(0)=84;WRITE(R(14)+R(0),F(6),4);R(0)=88;WRITE(R(14)+R(0),F(5),4);
            R(0)=124;for(unsigned k=0;k<6;k++){WRITE(R(14)+R(0),F(4),4);if(k<5)R(0)+=4;}
            R(3)=READ(R(15),4);R(0)=0x0c0a0b30;R(2)=8;WRITE(R(3),R(2),4);F(7)=READ(R(0),4);
            R(0)=0x0c0a0b34;F(5)=READ(R(0),4);R(0)=0x0c0a0b38;F(6)=READ(R(0),4);R(0)=0x0c0a0b3c;F(8)=READ(R(0),4);
            R(0)=0x0c0a0b40;F(4)=READ(R(0),4);op(s,6,15,'*');R(4)=READ(R(15),4);R(0)=0x0c0a0b44;op(s,4,15,'*');F(9)=READ(R(0),4);
            op(s,7,15,'*');R(4)+=4;R(0)=4;op(s,5,15,'*');op(s,8,15,'*');op(s,9,15,'*');
            for(unsigned k=0;k<8;k++){
                WRITE(R(4),F(k<4?7:5),4);WRITE(R(4)+R(0),F((k&2)?8:6),4);R(0)=R(2);WRITE(R(4)+R(0),F((k&1)?9:4),4);
                if(k<7){R(0)=4;R(4)+=12;}
            }
            R(11)+=12;R(0)=word(ram,0x0c0a0b28);WRITE(R(13)+R(0),F(14),4);R(3)=word(ram,0x0c0a0b2a);R(13)+=R(3);
        }
        R(2)=READ(R(15)+8,4);R(9)--;condition(s,R(9)==0);R(8)+=12;R(2)+=64;WRITE(R(15)+8,R(2),4);
    }while(!(R(17)&1));
    R(15)+=24;R(3)=READ(0x0c0a0b48,4);R(16)=pop(s,ram);R(4)=1;
    for(unsigned i=12;i<=15;i++)F(i)=pop(s,ram);
    for(unsigned i=8;i<=14;i++)R(i)=pop(s,ram);
    return vf3_matrix_family(R(3),s,ram)&&s->pc==R(16)&&ram->oob==0;
}
