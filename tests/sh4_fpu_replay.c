#include "fight/sh4_fpu.h"
#include <fenv.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(int argc,char **argv) {
    const char *path=argc>1?argv[1]:"extract/analysis/fsca_modes.bin";
    FILE *f=fopen(path,"rb");
    unsigned total=0,bad=0;
    if(!f) return 2;
    for(unsigned a=0;a<65536;++a) {
        uint32_t want[2],got[2];
        if(fread(want,4,2,f)!=2) return 2;
        vf3_fpu_fsca(a,got);
        if(memcmp(want,got,8)) { if(bad++<8) fprintf(stderr,"FSCA angle %04x differs\n",a); }
        ++total;
    }
    if(fgetc(f)!=EOF) return 2;
    fclose(f);
    char suite[1200]; snprintf(suite,sizeof(suite),"%s.ops",path);
    f=fopen(suite,"rb"); if(!f) return 2;
    fesetround(FE_UPWARD);
    uint32_t op;
    while(fread(&op,4,1,f)==1) {
        uint32_t in[54],want[54],got[54];
        if(fread(in,4,54,f)!=54 || fread(want,4,54,f)!=54) return 2;
        memcpy(got,in,sizeof(got));
        int ok=0;
        if(op==0xF37D) ok=vf3_fpu_fsrra(in[24],in[18],got+24);
        if(op==0xF0ED) ok=vf3_fpu_fipr(in+21,in+21,in[18],got+24);
        if(op==0xF1FD) ok=vf3_fpu_ftrv(in+37,in+21,in[18],got+21);
        if(op==0xF32D) { got[24]=vf3_fpu_float(in[53],in[18]); ok=1; }
        if(op==0xF33D) { got[53]=vf3_fpu_ftrc(in[24]); ok=1; }
        if(op==0xF34E) { got[24]=vf3_fpu_mac(in[21],in[25],in[24],in[18]); ok=1; }
        if(!ok || memcmp(want,got,sizeof(got)) || fegetround()!=FE_UPWARD) {
            if(bad++<8) for(unsigned j=0;j<54;++j) if(got[j]!=want[j]) {
                fprintf(stderr,"opcode %04x case %u word %u: %08x != %08x input %08x\n",op,total,j,got[j],want[j],in[j]); break;
            }
        }
        ++total;
    }
    if(ferror(f) || (total!=65536+12288 && total!=65536+147456)) return 2;
    fclose(f);
    /* Independent scalar expectations from the capture interpreter's SSE
     * operand order, including signaling NaNs and preserved sign/payload.
     * The corpus above does not exercise scalar binary arithmetic directly. */
    static const struct { uint32_t a,b,commutative,ordered; } nan_pairs[] = {
        {0xffffffffu,0xffc00000u,0xffc00000u,0xffffffffu},
        {0xffc00000u,0xffffffffu,0xffffffffu,0xffc00000u},
        {0x7f800001u,0xff800002u,0xffc00002u,0x7fc00001u},
        {0xff800002u,0x7f800001u,0x7fc00001u,0xffc00002u}
    };
    for(unsigned mode=0;mode<4;++mode) {
        uint32_t fpscr=(mode&1u)|((mode&2u)?0x40000u:0);
        for(unsigned i=0;i<sizeof(nan_pairs)/sizeof(nan_pairs[0]);++i) {
            const char operations[]="+*-/";
            for(unsigned j=0;j<sizeof(operations)-1;++j) {
                char operation=operations[j];
                uint32_t want=(operation=='+' || operation=='*')?
                    nan_pairs[i].commutative:nan_pairs[i].ordered;
                uint32_t got=vf3_fpu_binary(nan_pairs[i].a,nan_pairs[i].b,fpscr,operation);
                if(got!=want || fegetround()!=FE_UPWARD) {
                    if(bad++<8) fprintf(stderr,"NaN pair %u op %c mode %x: %08x != %08x\n",i,operation,fpscr,got,want);
                }
                ++total;
            }
        }
    }
    uint32_t sentinel=0x12345678u;
    if(vf3_fpu_fsrra(0x3F800000u,0x80000u,&sentinel) || sentinel!=0x12345678u || vf3_fpu_supported(2)) ++bad;
    fesetround(FE_TONEAREST);
    printf("sh4_fpu: %u/%u opcode cases match - %s\n",total-bad,total,bad?"FAIL":"PASS");
    return bad?1:0;
}
