#include "media/driver_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct memory {
    unsigned char bytes[0xa800];
    uint32_t writes[16][3];
    unsigned count;
} memory;
static uint32_t read32(void *context,uint32_t address)
{
    memory *m=context;
    return (uint32_t)m->bytes[address] | (uint32_t)m->bytes[address+1]<<8 |
           (uint32_t)m->bytes[address+2]<<16 | (uint32_t)m->bytes[address+3]<<24;
}
static void write32(void *context,uint32_t address,uint32_t value)
{
    memory *m=context;
    unsigned i;
    m->writes[m->count][0]=address;m->writes[m->count][1]=value;
    m->writes[m->count++][2]=4;
    for(i=0;i<4;++i)m->bytes[address+i]=(unsigned char)(value>>(8*i));
}
static void write8(void *context,uint32_t address,uint8_t value)
{
    memory *m=context;
    m->writes[m->count][0]=address;m->writes[m->count][1]=value;
    m->writes[m->count++][2]=1;m->bytes[address]=value;
}
static void seed(memory *m,uint32_t address,uint32_t value)
{ unsigned i;for(i=0;i<4;++i)m->bytes[address+i]=(unsigned char)(value>>(8*i)); }

int main(int argc,char **argv)
{
    FILE *input;
    unsigned passed=0,total=0,pop,forward,word,count,i,address,value,size;
    memory m;
    vf3_driver_memory io={&m,read32,write32,write8};
    if(argc!=2 || !(input=fopen(argv[1],"r")))return 2;
    while(fscanf(input,"%x %x %x %u",&pop,&forward,&word,&count)==4) {
        int match=1;
        memset(&m,0,sizeof(m));seed(&m,0x44,pop);seed(&m,0xa210,forward);
        seed(&m,0x400+pop,word);
        if(vf3_driver_handoff_a0(&io)!=VF3_DRIVER_HANDED_OFF || m.count!=count)match=0;
        for(i=0;i<count;++i) {
            if(fscanf(input,"%x %x %u",&address,&value,&size)!=3)return 2;
            if(i>=m.count || m.writes[i][0]!=address || m.writes[i][1]!=value || m.writes[i][2]!=size)match=0;
        }
        ++total;if(match)++passed;
    }
    fclose(input);
    /* Exercise the two independently sized rings at their last slots. This
     * fixture checks the recovered arithmetic, not a captured wrap event. */
    memset(&m,0,sizeof(m));seed(&m,0x44,0xfc);seed(&m,0xa210,0x3fc);
    seed(&m,0x4fc,0x040011a0);
    if(vf3_driver_handoff_a0(&io)!=VF3_DRIVER_HANDED_OFF || m.count!=9 ||
       read32(&m,0x44)!=0 || read32(&m,0xa210)!=0 ||
       read32(&m,0xa7fc)!=0xa0110044 || read32(&m,0x4fc)!=0)return 1;
    /* Empty, unsupported and malformed inputs cannot publish a command. */
    memset(&m,0,sizeof(m));
    if(vf3_driver_handoff_a0(&io)!=VF3_DRIVER_EMPTY || m.count)return 1;
    seed(&m,0x400,0xa8);
    if(vf3_driver_handoff_a0(&io)!=VF3_DRIVER_UNSUPPORTED || m.count)return 1;
    seed(&m,0x44,3);
    if(vf3_driver_handoff_a0(&io)!=VF3_DRIVER_INVALID_INPUT || m.count)return 1;
    if(vf3_driver_handoff_a0(NULL)!=VF3_DRIVER_INVALID_INPUT)return 1;
    printf("driver_queue: %u/%u observed store sequences match; wrap fixture and input guards PASS\n",passed,total);
    return total && passed==total?0:1;
}
