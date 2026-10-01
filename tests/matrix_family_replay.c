#include "port_harness.h"
#include "fight/matrix_family.h"
static FILE *xfin,*xfout,*extra,*gbr,*bank_file,*device_file;
static uint32_t entry;
typedef struct { uint32_t address,size,value,write; } DeviceAccess;
static struct { DeviceAccess *events; uint32_t capacity,count,pos,bad,first_bad; DeviceAccess expected,actual; } device_tape;
static void record_mismatch(DeviceAccess actual,DeviceAccess expected) {
    if(!device_tape.bad) {
        device_tape.first_bad=device_tape.pos ? device_tape.pos-1 : 0;
        device_tape.expected=expected; device_tape.actual=actual;
    }
    device_tape.bad=1;
}
static uint32_t device_read(void *context,uint32_t address,unsigned size) {
    (void)context;
    if(device_tape.pos>=device_tape.count) { record_mismatch((DeviceAccess){address,size,0,0},(DeviceAccess){0}); return 0; }
    DeviceAccess event=device_tape.events[device_tape.pos++];
    if(event.address!=address || event.size!=size || event.write)
        record_mismatch((DeviceAccess){address,size,event.value,0},event);
    return event.value;
}
static void device_write(void *context,uint32_t address,unsigned size,uint32_t value) {
    (void)context;
    if(device_tape.pos>=device_tape.count) { record_mismatch((DeviceAccess){address,size,value,1},(DeviceAccess){0}); return; }
    DeviceAccess event=device_tape.events[device_tape.pos++];
    if(event.address!=address || event.size!=size || !event.write || event.value!=value)
        record_mismatch((DeviceAccess){address,size,value,1},event);
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
    uint32_t bank_state[17];
    if(bank_file) {
        if(fread(bank_state,4,17,bank_file)!=17) { snprintf(err,len,"missing banked registers"); return 0; }
        state.bank_known=bank_state[0];
        memcpy(state.bank,bank_state+1,sizeof(state.bank));
    }
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
        if(device_tape.bad)
            snprintf(err,len,"device access mismatch at %u/%u: got %c %08x/%u=%08x, expected %c %08x/%u=%08x",
                     device_tape.first_bad,device_tape.count,
                     device_tape.actual.write?'W':'R',device_tape.actual.address,device_tape.actual.size,device_tape.actual.value,
                     device_tape.expected.write?'W':'R',device_tape.expected.address,device_tape.expected.size,device_tape.expected.value);
        else snprintf(err,len,"device tape has %u unconsumed events",device_tape.count-device_tape.pos);
        return 0;
    }
    if(!vf3h_regs_ok(c,state.v,err,len)) return 0;
    for(unsigned i=0;i<16;++i) if(state.v[37+i]!=wantxf[i]) { snprintf(err,len,"XF%u: %08x != %08x",i,state.v[37+i],wantxf[i]); return 0; }
    if(state.v[53]!=aux[1]) { snprintf(err,len,"FPUL: %08x != %08x",state.v[53],aux[1]); return 0; }
    if(state.pc!=aux[3]) { snprintf(err,len,"exit PC: %08x != %08x",state.pc,aux[3]); return 0; }
    if(state.gbr_known && state.gbr!=global[1]) { snprintf(err,len,"GBR differs"); return 0; }
    if(state.bank_known && memcmp(state.bank,bank_state+9,sizeof(state.bank))) {
        snprintf(err,len,"banked registers differ"); return 0;
    }
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
    snprintf(path,sizeof(path),"%s.bank.bin",stem); bank_file=fopen(path,"rb");
    snprintf(path,sizeof(path),"%s.dev.bin",stem); device_file=fopen(path,"rb");
    if(!xfin||!xfout||!extra) return 2;
    char *args[]={argv[0],argv[2]};
    int result=vf3h_harness_main(2,args,"matrix_family",argv[2],run_case);
    if(fgetc(xfin)!=EOF || fgetc(xfout)!=EOF || fgetc(extra)!=EOF) result=1;
    if(gbr && fgetc(gbr)!=EOF) result=1;
    if(bank_file && fgetc(bank_file)!=EOF) result=1;
    if(device_file && fgetc(device_file)!=EOF) result=1;
    fclose(xfin); fclose(xfout); fclose(extra); if(gbr) fclose(gbr); if(bank_file) fclose(bank_file);
    if(device_file) fclose(device_file); free(device_tape.events); return result;
}
