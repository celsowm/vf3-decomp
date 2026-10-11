/* Five render-command lanes, callable 0x0c05d424. Each enabled lane copies
 * the original eight-word template to its per-record destination in RAM.
 * The signed byte record offset and lane suppression are intentional.
 */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
#define READ(a) vf3_matrix_read(ram,(a),4)
#define WRITE(a,v) vf3_matrix_write(ram,(a),(v),4)
static void condition(vf3_matrix_state *s,int yes){R(17)=(R(17)&~1u)|(yes!=0);}
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t v){R(15)-=4;WRITE(R(15),v);}
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram){uint32_t v=READ(R(15));R(15)+=4;return v;}
int vf3_render_lanes_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    static const uint32_t continuation[5]={0x0c05d482,0x0c05d4c4,0x0c05d506,0x0c05d54a,0x0c05d58c};
    push(s,ram,R(14));push(s,ram,R(13));push(s,ram,R(12));R(13)=R(4);
    R(2)=READ(0x0c05d650);push(s,ram,R(11));push(s,ram,R(10));
    push(s,ram,R(9));push(s,ram,R(8));push(s,ram,R(16));
    R(3)=READ(0x0c05d654);R(15)-=32;R(14)=R(15);R(1)=R(15);R(0)=32;
    R(16)=0x0c05d444;
    if(!vf3_matrix_family(R(3),s,ram)||s->pc!=R(16))return 0;
    R(8)=READ(0x0c05d658);R(11)=READ(0x0c05d65c);R(12)=READ(0x0c05d660);
    for(unsigned lane=0;lane<5;lane++){
        if(lane==0){R(1)=READ(0x0c05d664);R(0)=READ(R(1));condition(s,(R(0)&1)==0);R(9)=8;}
        else if(lane==3){R(1)=READ(0x0c05d664);R(2)=READ(R(1));condition(s,(R(2)&R(9))==0);}
        else {R(3)=READ(0x0c05d664);R(0)=READ(R(3));condition(s,(R(0)&(1u<<lane))==0);}
        if(R(17)&1)continue;
        if(lane==3){R(0)=READ(0x0c05d678);WRITE(R(14),R(0));R(2)=READ(0x0c05d668);R(3)=READ(R(2));condition(s,R(3)==0);}
        else if(lane==0){R(0)=READ(0x0c05d668);R(3)=READ(R(0));condition(s,R(3)==0);}
        else {
            R(1)=READ(0x0c05d670+(lane-1)*4);
            if(lane!=2)R(0)=READ(0x0c05d668);
            WRITE(R(14),R(1));
            if(lane==2)R(0)=READ(0x0c05d668);
            R(2)=READ(R(0));condition(s,R(2)==0);
        }
        if(!(R(17)&1)){
            unsigned scratch=(lane==0||lane==3)?3:2;
            R(scratch)=READ(0x0c05d66c);R(0)=READ(R(scratch));condition(s,R(0)==32+lane);
            if(R(17)&1)continue;
        }
        R(10)=0;R(3)=R(10);condition(s,R(3)>=R(13));
        if(!(R(17)&1))do {
            R(6)=32;R(5)=R(14);R(4)=R(10);R(3)=R(10);
            R(4)<<=2;R(4)+=R(3);R(4)<<=2;
            R(4)=(uint32_t)(int32_t)(int8_t)R(4);R(4)+=R(11);
            R(4)=READ(R(4)+lane*4);R(16)=continuation[lane];
            if(!vf3_matrix_family(R(12),s,ram)||s->pc!=R(16))return 0;
            R(10)++;condition(s,R(10)>=R(13));
        }while(!(R(17)&1));
        if(lane==2){R(3)=8;WRITE(R(8)+8,R(3));}
        else WRITE(R(8)+lane*4,R(9));
    }
    R(15)+=32;R(16)=pop(s,ram);R(8)=pop(s,ram);R(9)=pop(s,ram);
    R(10)=pop(s,ram);R(11)=pop(s,ram);R(12)=pop(s,ram);R(13)=pop(s,ram);R(14)=pop(s,ram);
    s->pc=R(16);return ram->oob==0;
}
