/* Script opcode 34 recomposes the fighter's horizontal position from its
 * model-relative offsets, using the game's sine/cosine helpers. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#define R(n) s->v[n]
#define F(n) s->v[21+(n)]
#define word(a) vf3_matrix_read(ram,(a),4)
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t value)
{ R(15)-=4; vf3_matrix_write(ram,R(15),value,4); }
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram)
{ uint32_t value=word(R(15)); R(15)+=4; return value; }
static void condition(vf3_matrix_state *s,int value)
{ R(17)=(R(17)&~1u)|(value!=0); }
static void binary(vf3_matrix_state *s,unsigned dst,unsigned src,char op)
{ F(dst)=vf3_fpu_binary(F(dst),F(src),R(18),op); }
static int trig(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t target,uint32_t back)
{ R(4)=R(13); R(16)=back; return vf3_matrix_family(target,s,ram)&&s->pc==back; }
int vf3_script_position_command(uint32_t entry,vf3_matrix_state *s,const vf3_ram_map *ram)
{
    unsigned step=(R(18)&0x100000u)?8:4;
    if(entry==0x0c0af37c) {
        push(s,ram,R(14)); R(14)=R(4); push(s,ram,R(13)); push(s,ram,R(12));
        for(int i=15;i>=12;--i) { R(15)-=step; vf3_matrix_store(s,ram,i,R(15)); }
    }
    push(s,ram,R(16)); R(15)-=12; vf3_matrix_write(ram,R(15),R(5),4);
    R(4)=word(0x0c0af4dc); R(5)=word(0x0c0af4e0);
    R(3)=word(R(4)+4); condition(s,!(R(3)&R(5))); R(12)=R(6);
    if(R(17)&1u) {
        R(2)=word(R(4)); condition(s,!(R(2)&R(5)));
        if(R(17)&1u) {
            R(0)=(uint32_t)(int32_t)(int16_t)vf3_matrix_read(ram,R(14)+30,2);
            vf3_matrix_write(ram,R(14)+30,R(0),2); R(4)=R(0); R(13)=R(0);
            R(0)=16; R(3)=R(4); R(3)-=R(4); R(4)=R(3)&65535;
            vf3_matrix_write(ram,R(15)+8,R(4),4);
            vf3_matrix_load(s,ram,4,R(14)+R(0)); R(0)=24;
            vf3_matrix_load(s,ram,5,R(14)+R(0)); R(0)=0x430;
            vf3_matrix_load(s,ram,13,R(14)+R(0)); R(0)+=8;
            vf3_matrix_load(s,ram,12,R(14)+R(0)); R(0)=4;
            vf3_matrix_move(s,15,13); binary(s,15,4,'-');
            vf3_matrix_move(s,3,12); binary(s,3,5,'-');
            vf3_matrix_store(s,ram,3,R(15)+R(0)); R(13)=word(R(15)+8);
            R(3)=word(0x0c0af4e4); R(13)=(uint32_t)(int32_t)(int16_t)R(13);
            if(!trig(s,ram,R(3),0x0c0af3da)) return 0;
            vf3_matrix_move(s,3,15); vf3_matrix_move(s,15,0); binary(s,15,3,'*');
            R(3)=word(0x0c0af4e8); vf3_matrix_move(s,4,0);
            if(!trig(s,ram,R(3),0x0c0af3e8)) return 0;
            R(0)=4; vf3_matrix_move(s,4,0); vf3_matrix_load(s,ram,3,R(15)+R(0));
            vf3_matrix_move(s,2,15); binary(s,4,3,'*'); R(3)=word(0x0c0af4e8);
            vf3_matrix_move(s,15,4); binary(s,15,2,'+');
            if(!trig(s,ram,R(3),0x0c0af3fc)) return 0;
            vf3_matrix_move(s,14,0); binary(s,14,15,'*');
            R(2)=word(0x0c0af4e4); vf3_matrix_move(s,4,0);
            if(!trig(s,ram,R(2),0x0c0af408)) return 0;
            vf3_matrix_move(s,4,0); binary(s,4,14,'*'); vf3_matrix_move(s,3,14);
            R(0)=16; vf3_matrix_move(s,14,4); binary(s,14,3,'-');
            vf3_matrix_move(s,3,15); vf3_matrix_move(s,15,13); binary(s,15,3,'-');
            vf3_matrix_move(s,3,14); vf3_matrix_move(s,14,12); binary(s,14,3,'-');
            vf3_matrix_store(s,ram,15,R(14)+R(0)); R(0)=24;
            vf3_matrix_store(s,ram,14,R(14)+R(0));
        }
    }
    R(3)=word(R(12)+8); R(6)=R(12); R(4)=R(14); R(3)+=5;
    vf3_matrix_write(ram,R(12)+8,R(3),4); R(5)=word(R(15)); R(15)+=12;
    R(16)=pop(s,ram); R(3)=word(0x0c0af4ec);
    for(unsigned i=12;i<=15;++i) { vf3_matrix_load(s,ram,i,R(15)); R(15)+=step; }
    R(12)=pop(s,ram); R(13)=pop(s,ram); R(14)=pop(s,ram);
    return vf3_matrix_family(R(3),s,ram);
}
