#include "port_harness.h"
#include "fight/matrix_family.h"
static FILE *xfin,*xfout,*extra,*gbr;
static uint32_t entry;
static int run_case(const vf3_case*c,vf3_harness_mem*m,char*err,size_t len) {
    vf3_matrix_state state;
    memset(&state,0,sizeof(state)); state.budget=100000;
    uint32_t wantxf[16],aux[4];
    memcpy(state.v,c->in,sizeof(c->in));
    if(fread(state.v+37,4,16,xfin)!=16 || fread(wantxf,4,16,xfout)!=16 || fread(aux,4,4,extra)!=4) {
        snprintf(err,len,"missing extended state"); return 0;
    }
    state.v[53]=aux[0];
    uint32_t global[3]={0};
    if(gbr && fread(global,4,3,gbr)!=3) { snprintf(err,len,"missing GBR state"); return 0; }
    state.gbr=global[0]; state.gbr_known=global[2];
    if(!vf3_matrix_family(entry,&state,&m->ram)) { snprintf(err,len,"unsupported helper/state at %08x PC %08x (%u OOB)",entry,state.failed_pc,m->ram.oob); return 0; }
    if(!vf3h_regs_ok(c,state.v,err,len)) return 0;
    for(unsigned i=0;i<16;++i) if(state.v[37+i]!=wantxf[i]) { snprintf(err,len,"XF%u: %08x != %08x",i,state.v[37+i],wantxf[i]); return 0; }
    if(state.v[53]!=aux[1]) { snprintf(err,len,"FPUL: %08x != %08x",state.v[53],aux[1]); return 0; }
    if(state.pc!=aux[3]) { snprintf(err,len,"exit PC: %08x != %08x",state.pc,aux[3]); return 0; }
    if(state.gbr_known && state.gbr!=global[1]) { snprintf(err,len,"GBR differs"); return 0; }
    return vf3h_mem_ok(m,err,len);
}
int main(int argc,char**argv) {
    if(argc!=3) { fprintf(stderr,"usage: vf3matrixfamily entry cases\n"); return 2; }
    entry=(uint32_t)strtoul(argv[1],NULL,0);
    char path[1400],stem[1200]; snprintf(stem,sizeof(stem),"%s",argv[2]);
    char *ext=strrchr(stem,'.'); if(!ext) return 2; *ext=0;
    snprintf(path,sizeof(path),"%s.xfin.bin",stem); xfin=fopen(path,"rb");
    snprintf(path,sizeof(path),"%s.xfout.bin",stem); xfout=fopen(path,"rb");
    snprintf(path,sizeof(path),"%s.extra.bin",stem); extra=fopen(path,"rb");
    snprintf(path,sizeof(path),"%s.gbr.bin",stem); gbr=fopen(path,"rb");
    if(!xfin||!xfout||!extra) return 2;
    char *args[]={argv[0],argv[2]};
    int result=vf3h_harness_main(2,args,"matrix_family",argv[2],run_case);
    if(fgetc(xfin)!=EOF || fgetc(xfout)!=EOF || fgetc(extra)!=EOF) result=1;
    if(gbr && fgetc(gbr)!=EOF) result=1;
    fclose(xfin); fclose(xfout); fclose(extra); if(gbr) fclose(gbr); return result;
}
