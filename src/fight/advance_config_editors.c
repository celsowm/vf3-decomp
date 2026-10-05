/* Scene configuration editors: field type, bounds and increment recovered
 * with tools/oracle/config_editor_map.py from the untouched original image. */
#include "fight/matrix_family.h"
#define R(n) s->v[(n)]
typedef struct { uint32_t entry; unsigned offset,width,minimum,maximum,step; } Editor;
static const Editor editors[] = {
    {0x0c08e1cc,0,1,2,5,1},
    {0x0c08e200,1,1,2,5,1}, {0x0c08e238,2,1,0,3,1},
    {0x0c08e2b6,4,2,160,360,10}, {0x0c08e2ee,6,2,180,400,10},
    {0x0c08e326,3,1,0,1,1}, {0x0c08e35e,16,1,0,1,1},
    {0x0c08e396,17,1,0,1,1}, {0x0c08e3ce,18,1,0,3,1},
    {0x0c08e426,19,1,0,10,1}, {0x0c08e45e,14,1,0,1,1},
    {0x0c08e49a,15,1,0,1,1}, {0x0c08e4d6,21,1,0,1,1},
    {0x0c08e50e,20,1,0,1,1}, {0x0c08e57e,12,1,0,1,1}
};
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram)
{ uint32_t value=vf3_matrix_read(ram,R(15),4); R(15)+=4; return value; }
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t value)
{ R(15)-=4; vf3_matrix_write(ram,R(15),value,4); }
static int call(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t target,uint32_t continuation)
{ R(16)=continuation; return vf3_matrix_family(target,s,ram) && s->pc==continuation; }

int vf3_advance_config_editors_contains(uint32_t entry)
{
    switch(entry&0x1fffffffu) {
    case 0x0c08e1cc: return 1;
    case 0x0c08e200: case 0x0c08e238: case 0x0c08e2b6: case 0x0c08e2ee:
    case 0x0c08e326: case 0x0c08e35e: case 0x0c08e396: case 0x0c08e3ce:
    case 0x0c08e426: case 0x0c08e45e: case 0x0c08e49a: case 0x0c08e4d6:
    case 0x0c08e50e: case 0x0c08e57e: return 1;
    default: return 0;
    }
}
int vf3_advance_config_editors(uint32_t entry,vf3_matrix_state *s,const vf3_ram_map *ram)
{
    const Editor *editor=0;
    for(unsigned i=0;i<sizeof(editors)/sizeof(editors[0]);++i)
        if(editors[i].entry==(entry&0x1fffffffu)) { editor=&editors[i]; break; }
    if(!editor) { s->failed_pc=entry; return 0; }
    push(s,ram,R(16)); R(15)-=8;
    vf3_matrix_write(ram,R(15)+4,R(4),4);
    R(14)=0x0c11e504; R(3)=editor->width==1?0x0c0c66b8:0x0c0c66c0;
    R(4)=R(14)+editor->offset;
    if(!call(s,ram,R(3),editor->entry+(editor->offset?16:14))) return 0;
    R(0)&=editor->width==1?255u:65535u;
    R(3)=editor->maximum; vf3_matrix_write(ram,R(15),R(0),4);
    push(s,ram,R(3)); R(7)=editor->minimum;
    R(5)=vf3_matrix_read(ram,R(15)+8,4); R(6)=editor->step;
    R(2)=0x0c072ec2; R(4)=vf3_matrix_read(ram,R(15)+4,4);
    if(!call(s,ram,R(2),editor->entry+(editor->offset?36:34))) return 0;
    vf3_matrix_write(ram,R(15)+4,R(0),4); R(15)+=12;
    R(16)=pop(s,ram); R(3)=editor->width==1?0x0c0c66d0:0x0c0c66d4;
    R(4)=R(14); R(5)=R(0); R(4)+=editor->offset; R(14)=pop(s,ram);
    return vf3_matrix_family(R(3),s,ram);
}
