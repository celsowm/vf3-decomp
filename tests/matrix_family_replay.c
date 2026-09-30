#include "port_harness.h"
#include "fight/matrix_family.h"
static FILE *xfin,*xfout,*extra,*gbr,*device_file;
static uint32_t entry;
typedef struct { uint32_t address,size,value,write; } DeviceAccess;
static struct { DeviceAccess *events; uint32_t capacity,count,pos,bad; } device_tape;
static uint32_t device_read(void *context,uint32_t address,unsigned size) {
    (void)context;
    if(device_tape.pos>=device_tape.count) { device_tape.bad=1; return 0; }
    DeviceAccess event=device_tape.events[device_tape.pos++];
    if(event.address!=address || event.size!=size || event.write) device_tape.bad=1;
    return event.value;
}
static void device_write(void *context,uint32_t address,unsigned size,uint32_t value) {
    (void)context;
    if(device_tape.pos>=device_tape.count) { device_tape.bad=1; return; }
    DeviceAccess event=device_tape.events[device_tape.pos++];
    if(event.address!=address || event.size!=size || !event.write || event.value!=value) device_tape.bad=1;
}
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
    if(device_file) {
        uint32_t count;
        if(fread(&count,4,1,device_file)!=1 || count>16384) { snprintf(err,len,"invalid device tape"); return 0; }
        if(count>device_tape.capacity) {
            DeviceAccess *events=realloc(device_tape.events,(size_t)count*sizeof(*events));
            if(!events) { snprintf(err,len,"device tape allocation failed"); return 0; }
            device_tape.events=events; device_tape.capacity=count;
        }
        if(fread(device_tape.events,sizeof(DeviceAccess),count,device_file)!=count) { snprintf(err,len,"short device tape"); return 0; }
        device_tape.count=count; device_tape.pos=device_tape.bad=0;
        m->ram.device_read=device_read; m->ram.device_write=device_write;
    }
    if(!vf3_matrix_family(entry,&state,&m->ram)) { snprintf(err,len,"unsupported helper/state at %08x PC %08x (%u OOB)",entry,state.failed_pc,m->ram.oob); return 0; }
    if(device_file && (device_tape.bad || device_tape.pos!=device_tape.count)) {
        snprintf(err,len,"device access mismatch at %u/%u",device_tape.pos,device_tape.count); return 0;
    }
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
    snprintf(path,sizeof(path),"%s.dev.bin",stem); device_file=fopen(path,"rb");
    if(!xfin||!xfout||!extra) return 2;
    char *args[]={argv[0],argv[2]};
    int result=vf3h_harness_main(2,args,"matrix_family",argv[2],run_case);
    if(fgetc(xfin)!=EOF || fgetc(xfout)!=EOF || fgetc(extra)!=EOF) result=1;
    if(gbr && fgetc(gbr)!=EOF) result=1;
    if(device_file && fgetc(device_file)!=EOF) result=1;
    fclose(xfin); fclose(xfout); fclose(extra); if(gbr) fclose(gbr);
    if(device_file) fclose(device_file); free(device_tape.events); return result;
}
