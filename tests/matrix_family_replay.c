#include "port_harness.h"
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
#include "fight/readable.h"
#include "oracle_sidecars.h"

static vf3h_sidecars sc;
static uint32_t entry;

/* The sidecar machinery (the XF registers, the FPUL, the GBR, the banked
 * registers, the drive state and the device tape) lives in
 * tests/oracle_sidecars.h, shared with the readable ports' oracle legs. */

static int run_case(const vf3_case*c,vf3_harness_mem*m,char*err,size_t len) {
    vf3_matrix_state state;
    memset(&state,0,sizeof(state));
    /* The alias handoff is per case: a stale one from the previous case would
     * give the entry the wrong mirror (0x0c/0x8c/0xac) to compute addresses
     * with. */
    vf3_matrix_call_alias=0u; vf3_matrix_call_alias_pc=0xffffffffu;
    /* The step budget has to cover the reference's own instruction count for
     * the case: a body with a counted loop (e.g. 0x8c04ba30 copies 50464
     * bytes) needs far more than 100k steps, and the port spends one step
     * per emulated instruction just like the oracle does. */
    state.budget=4000000;
    memcpy(state.v,c->in,sizeof(c->in));
    if(!vf3h_sidecars_load(&sc,c,&state,&m->ram,err,len)) return 0;
    if(!vf3_matrix_family(entry,&state,&m->ram)) { snprintf(err,len,"unsupported helper/state at %08x PC %08x (%u OOB)",entry,state.failed_pc?state.failed_pc:state.lost_pc,m->ram.oob); return 0; }
    if(!vf3h_sidecars_devices_ok(&sc,err,len)) return 0;
    if(!vf3h_regs_ok(c,state.v,err,len)) return 0;
    for(unsigned i=0;i<16;++i) if(state.v[37+i]!=sc.wantxf[i]) { snprintf(err,len,"XF%u: %08x != %08x",i,state.v[37+i],sc.wantxf[i]); return 0; }
    if(state.v[53]!=sc.aux[1]) { snprintf(err,len,"FPUL: %08x != %08x",state.v[53],sc.aux[1]); return 0; }
    if(state.pc!=sc.aux[3]) { snprintf(err,len,"exit PC: %08x != %08x",state.pc,sc.aux[3]); return 0; }
    if(state.gbr_known && state.gbr!=sc.global[1]) { snprintf(err,len,"GBR differs"); return 0; }
    if(sc.bank_valid && memcmp(state.bank,sc.bank_state+9,sizeof(state.bank))) {
        snprintf(err,len,"banked registers differ"); return 0;
    }
    return vf3h_mem_ok(m,err,len);
}
/* VF3_READABLE=1: let the readable ports of src/fight/readable.c pre-empt the generated chain, so the same oracle cases
 * check the readable C instead of the generated adapter. */
static unsigned readable_used;
/* VF3_READABLE_ONLY=<entry>: serve only that one entry readably.  The whole
 * table pre-empts too much for a specimen whose other legs are not ported
 * yet; this switch lets a single port be proved inside a corpus whose call
 * tree reaches it. */
static uint32_t readable_only;
static int readable_hook(uint32_t e,vf3_matrix_state*s,const vf3_ram_map*ram,int*handled) {
    if(readable_only && (e&0x1FFFFFFFu)!=(readable_only&0x1FFFFFFFu)) { *handled=0; return 0; }
    const int ok=vf3_readable_override(e,s,ram,handled);
    if(*handled) ++readable_used;
    return ok;
}
int main(int argc,char**argv) {
    if(getenv("VF3_READABLE")) {
        const char *only=getenv("VF3_READABLE_ONLY");
        if(only&&*only) readable_only=(uint32_t)strtoul(only,NULL,0);
        vf3_family_override=readable_hook;
    }
    if(getenv("VF3_COMPLETE_CALLS")) vf3_family_complete_calls=1;
    /* A module that reaches a register-indirect jump whose target it was not
     * generated with stops at that target with the jump already taken.  The
     * reference continues there as the tail transfer it is, so the replay does
     * too: the dispatcher resumes at the lost PC instead of failing there.
     * Set VF3_TAIL_RETRY=0 to keep the strict single-module behaviour. */
    { const char *tr=getenv("VF3_TAIL_RETRY"); vf3_family_tail_retry=(!tr||tr[0]!='0'); }
    if(argc!=3) { fprintf(stderr,"usage: vf3matrixfamily entry cases\n"); return 2; }
    entry=(uint32_t)strtoul(argv[1],NULL,0);
    char path[1400],stem[1200]; snprintf(stem,sizeof(stem),"%s",argv[2]);
    char *ext=strrchr(stem,'.'); if(!ext) return 2; *ext=0;
    if(!vf3h_sidecars_open(&sc,stem)) return 2;
    char *args[]={argv[0],argv[2]};
    int result=vf3h_harness_main(2,args,"matrix_family",argv[2],run_case);
    if(getenv("VF3_READABLE")) printf("readable ports used: %u calls\n",readable_used);
    vf3h_sidecars_close(&sc); return result;
}
