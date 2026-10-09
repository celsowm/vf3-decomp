/* Install a motion descriptor's actor fields, refresh a changed motion's
 * packed record, then run the original frame-selection and motion helpers. */
#include "fight/matrix_family.h"
#define R(n) s->v[n]
#define word(a) vf3_matrix_read(ram,(a),4)
static void condition(vf3_matrix_state *s,int value)
{ R(17)=(R(17)&~1u)|(value!=0); }
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t value)
{ R(15)-=4; vf3_matrix_write(ram,R(15),value,4); }
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram)
{ uint32_t value=word(R(15)); R(15)+=4; return value; }
static uint32_t signed_word(const vf3_ram_map *ram,uint32_t address)
{ return (uint32_t)(int32_t)(int16_t)vf3_matrix_read(ram,address,2); }
static int call(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t target,uint32_t back)
{ R(4)=R(14); R(16)=back; return vf3_matrix_family(target,s,ram)&&s->pc==back; }
int vf3_motion_descriptor_command(uint32_t entry,vf3_matrix_state *s,const vf3_ram_map *ram)
{
    if(entry==0x0c0a8d58) { R(0)=4; push(s,ram,R(14)); }
    push(s,ram,R(16)); R(14)=R(4); R(2)=word(R(6)); R(3)=0xfffffffe;
    R(15)-=8; R(2)&=R(3); vf3_matrix_write(ram,R(14),R(2),4);
    vf3_matrix_load(s,ram,4,R(6)+R(0)); R(0)=8;
    vf3_matrix_load(s,ram,5,R(6)+R(0)); R(0)=12;
    vf3_matrix_load(s,ram,6,R(6)+R(0)); R(0)=signed_word(ram,R(6)+20);
    R(4)=word(R(6)+16); R(7)=R(0); R(0)=signed_word(ram,R(6)+24);
    vf3_matrix_write(ram,R(15),R(0),2); R(0)=16; R(2)=word(R(6)+28);
    vf3_matrix_write(ram,R(15)+4,R(2),4);
    vf3_matrix_store(s,ram,4,R(14)+R(0)); R(0)=20;
    vf3_matrix_store(s,ram,5,R(14)+R(0)); R(0)=24;
    vf3_matrix_store(s,ram,6,R(14)+R(0)); R(0)=72;
    vf3_matrix_write(ram,R(14)+R(0),R(4),4); R(0)=R(7);
    vf3_matrix_write(ram,R(14)+30,R(0),2); R(2)=signed_word(ram,R(15)); R(0)=62;
    vf3_matrix_write(ram,R(14)+R(0),R(2),2); R(0)=0x1a04; R(1)=word(R(15)+4);
    vf3_matrix_write(ram,R(14)+R(0),R(1),4); R(0)=60;
    R(7)=signed_word(ram,R(14)+R(0)); R(0)=signed_word(ram,R(6)+22);
    R(4)=R(0); R(6)=(uint32_t)(int32_t)(int16_t)R(4); condition(s,R(6)==0);
    R(0)=60; vf3_matrix_write(ram,R(14)+R(0),R(4),2);
    if(!(R(17)&1u)) {
        R(7)=(uint32_t)(int32_t)(int16_t)R(7); condition(s,R(7)==R(6));
        int first_frame=0;
        if(R(17)&1u) {
            R(0)=62; R(4)=signed_word(ram,R(14)+R(0));
            R(0)=(uint32_t)(int32_t)(int16_t)R(4); condition(s,R(0)==1);
            first_frame=(R(17)&1u)!=0;
        } else {
            R(2)=vf3_matrix_read(ram,R(14)+R(0),2); R(6)=R(2);
            vf3_matrix_write(ram,R(15),R(2),4); R(3)=word(0x0c0a8e04);
            if(!call(s,ram,R(3),0x0c0a8dd6)) return 0;
            R(2)=word(0x0c0a8e08);
            if(!call(s,ram,R(2),0x0c0a8ddc)) return 0;
            first_frame=1;
        }
        R(3)=word(first_frame?0x0c0a8e0c:0x0c0a8e10);
        if(!call(s,ram,R(3),first_frame?0x0c0a8de2:0x0c0a8dec)) return 0;
        R(15)+=8; R(2)=word(0x0c0a8e14); R(16)=pop(s,ram); R(4)=R(14); R(14)=pop(s,ram);
        return vf3_matrix_family(R(2),s,ram);
    }
    R(15)+=8; R(16)=pop(s,ram); R(14)=pop(s,ram); s->pc=R(16);
    return ram->oob==0;
}
