/* Readable state helpers versus the retained original static translation.
 * Includes zero-length comparison, every mismatch position, high-bit bytes,
 * checksum table stride/sign extension, scratch RAM and all ABI registers. */
#include "fight/matrix_family.h"
#include <stdio.h>
#include <string.h>

int vf3_advance_small_tail_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);

#define BASE 0x0c400000u
static uint8_t original[4096],readable[4096];
static uint8_t table_pointer[4]={0x00,0x02,0x40,0x0c};
static unsigned cases;

static int compare(uint32_t entry,unsigned length,int mismatch,unsigned palette)
{
    vf3_matrix_state a={0},b;
    for(unsigned i=0;i<sizeof(original);++i) original[i]=(uint8_t)(i*73+palette);
    memcpy(original+128,original,65);
    if(mismatch>=0) original[128+mismatch]^=0xff;
    /* Each four-byte entry has a signed word and two poisoned padding bytes. */
    for(unsigned i=0;i<256;++i) {
        uint16_t word=(uint16_t)(i*197+0x8001);
        original[512+4*i]=(uint8_t)word;
        original[513+4*i]=(uint8_t)(word>>8);
        original[514+4*i]=0xab; original[515+4*i]=0xcd;
    }
    memcpy(readable,original,sizeof(original));
    for(unsigned i=0;i<54;++i) a.v[i]=0x76543210u+i;
    a.v[4]=BASE; a.v[5]=entry==0x0c042fdc?BASE+128:length;
    a.v[6]=length; a.v[15]=BASE+4092; a.v[16]=0x0c123456;
    a.v[17]=0x301; a.v[18]=0; a.budget=100000; b=a;
    vf3_ram_win aw[]={{original,BASE,sizeof(original)},
                     {table_pointer,0x0c076b68,4}};
    vf3_ram_win bw[]={{readable,BASE,sizeof(readable)},
                     {table_pointer,0x0c076b68,4}};
    vf3_ram_map am={aw,2,0,0,0,0},bm={bw,2,0,0,0,0};
    if(!vf3_advance_small_tail_adapter(entry,&a,&am) ||
       !vf3_matrix_family(entry,&b,&bm) ||
       memcmp(a.v,b.v,sizeof(a.v)) || a.pc!=b.pc ||
       a.failed_pc!=b.failed_pc || am.oob || bm.oob ||
       memcmp(original,readable,sizeof(original))) {
        fprintf(stderr,"state helpers: %08x length=%u mismatch=%d palette=%u failed\n",
                entry,length,mismatch,palette);
        return 0;
    }
    ++cases; return 1;
}

int main(void)
{
    const unsigned palettes[]={0,127,128,255};
    for(unsigned p=0;p<4;++p) {
        for(unsigned length=0;length<=64;++length)
            for(int mismatch=-1;mismatch<(int)length;++mismatch)
                if(!compare(0x0c042fdc,length,mismatch,palettes[p])) return 1;
        for(unsigned length=1;length<=64;++length)
            if(!compare(0x0c076b3c,length,-1,palettes[p])) return 1;
    }
    /* Zero comparison length touches neither buffer, even for unmapped pointers. */
    vf3_matrix_state empty={0}; empty.v[4]=1; empty.v[5]=2;
    empty.v[2]=0x1234; empty.v[3]=0x5678; empty.v[16]=0x0c123456;
    vf3_ram_map unmapped={0};
    if(!vf3_matrix_family(0x0c042fdc,&empty,&unmapped) || unmapped.oob ||
       empty.v[0]!=0 || empty.v[2]!=0x1234 || empty.v[3]!=0x5678 ||
       empty.v[4]!=1 || empty.v[7]!=2 || empty.pc!=empty.v[16]) return 1;
    /* Original checksum is a do/while countdown: length zero must not succeed. */
    vf3_matrix_state s={0}; s.v[4]=BASE; s.v[15]=BASE+4092; s.budget=3;
    vf3_ram_win windows[]={{readable,BASE,sizeof(readable)},
                          {table_pointer,0x0c076b68,4}};
    vf3_ram_map ram={windows,2,0,0,0,0};
    if(vf3_matrix_family(0x0c076b3c,&s,&ram) ||
       s.failed_pc!=0x0c076b40 || s.v[5]!=0xfffffffdu || ram.oob) return 1;
    printf("state_helpers: %u differential cases and zero-length boundaries - PASS\n",cases);
    return 0;
}
