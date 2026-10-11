/* Cooperative resource-task driver, full entry 0x8c04bd62.
 * Task records have a 188-byte stride. A restore transfers control to the
 * saved job continuation; it does not necessarily return to the driver. */
#include "fight/matrix_family.h"
#include <setjmp.h>
struct vf3_task_driver_scope {
    jmp_buf jump;
    struct vf3_task_driver_scope *previous;
    uint32_t resume_pc, resume_sp;
};
#define R(n) s->v[(n)]
#define READ(a) vf3_matrix_read(ram,(a),4)
#define WRITE(a,v) vf3_matrix_write(ram,(a),(v),4)
static void push(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t v)
{ R(15)-=4;WRITE(R(15),v); }
static uint32_t pop(vf3_matrix_state *s,const vf3_ram_map *ram)
{ uint32_t v=READ(R(15));R(15)+=4;return v; }
static void condition(vf3_matrix_state *s,int v)
{ R(17)=(R(17)&~1u)|(v!=0); }
static void set_fpscr(vf3_matrix_state *s,uint32_t value)
{
    /* Loading FPSCR exchanges FR/XF when the selected bank changes. */
    if((R(18)^value)&0x200000u)vf3_matrix_swap(s);
    R(18)=value;
}
static int call(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t target,uint32_t ret)
{ R(16)=ret;return vf3_matrix_family(target,s,ram); }

/* A restored guest stack can retire any number of host adapter calls. Run
 * the real SDK restore first, then unwind to the owning C driver scope. */
int vf3_task_driver_restore_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    struct vf3_task_driver_scope *scope;
    if(!vf3_eighth_adapter(0x0c054454u,s,ram))return 0;
    for(scope=s->task_driver;scope;scope=scope->previous){
        if(s->pc==scope->resume_pc && R(15)==scope->resume_sp){
            s->task_driver=scope;
            longjmp(scope->jump,1);
        }
    }
    return ram->oob==0;
}

int vf3_task_driver_c(vf3_matrix_state *s,const vf3_ram_map *ram,uint32_t alias)
{
    struct vf3_task_driver_scope scope;
    int result;
    push(s,ram,R(14));push(s,ram,R(13));R(13)=R(4);
    push(s,ram,R(12));R(4)=R(13);push(s,ram,R(11));R(12)=0;
    push(s,ram,R(10));push(s,ram,R(9));
    R(9)=0x0c1b2088;R(2)=0x0c1b208c;R(3)=READ(R(9));
    push(s,ram,R(16));WRITE(R(2),R(3));
    R(3)=R(18);R(15)-=4;WRITE(R(9),R(13));
    R(14)=0x140;WRITE(R(15),R(3));R(1)=0x40001;
    R(14)+=R(13);R(3)=0x0c0544c8;set_fpscr(s,R(1));R(4)+=4;
    if(!call(s,ram,R(3),alias+0x4bd94))return 0;
    if(s->pc!=alias+0x4bd94)return vf3_matrix_family(s->pc,s,ram);
    scope.previous=s->task_driver;
    scope.resume_pc=alias+0x4bd94;scope.resume_sp=R(15);
    s->task_driver=&scope;
    /* The original SDK restore has already restored guest registers/RAM
     * before the native escape reaches this saved C continuation. */
    if(setjmp(scope.jump)) { /* Resume at the original 0x0c04bd94. */ }
    R(10)=0x0c054454;R(11)=3;
    for(;;){
        R(0)=0x138;R(2)=READ(R(13)+R(0));
        condition(s,(int32_t)R(12)>=(int32_t)R(2));
        if(R(17)&1u)break;
        if(!s->budget){s->failed_pc=alias+0x4bdbc;goto failed;}
        --s->budget;
        R(0)=0x18c0;WRITE(R(13)+R(0),R(14));
        R(0)=READ(R(14)+12);condition(s,R(0)==0);
        if(!(R(17)&1u)){
            condition(s,R(0)==1);
            if(R(17)&1u){
                R(0)=0x134;R(3)=READ(R(14)+20);R(2)=READ(R(13)+R(0));
                condition(s,R(3)>R(2));
                if(!(R(17)&1u)){
                    R(4)=R(14);R(5)=1;R(4)+=24;
                    if(!call(s,ram,R(10),alias+0x4bdee))goto failed;
                    /* A restored job can return through several caller
                     * continuations before yielding or retiring. Follow those
                     * transfers on its guest stack. The SDK restore hook
                     * unwinds back to our saved driver continuation. */
                    while(s->pc!=alias+0x4bdee){
                        if(!vf3_matrix_family(s->pc,s,ram))goto failed;
                    }
                }
            }else{
                condition(s,R(0)==2);
                if(R(17)&1u){
                    WRITE(R(14)+12,R(11));R(3)=0x0c04bc52;
                    WRITE(R(14)+32,R(3));
                }else{
                    condition(s,R(0)==3);
                    if(R(17)&1u){
                        R(5)=R(14);R(4)=R(13);
                        if(!call(s,ram,0x0c04bbc6,alias+0x4bdd8))goto failed;
                        if(s->pc!=alias+0x4bdd8){
                            result=vf3_matrix_family(s->pc,s,ram);
                            s->task_driver=scope.previous;return result;
                        }
                    }
                }
            }
        }
        R(3)=188;++R(12);R(14)+=R(3);
    }
    R(0)=0x134;R(2)=READ(R(13)+R(0));++R(2);WRITE(R(13)+R(0),R(2));
    R(1)=0x0c1b208c;R(3)=READ(R(1));WRITE(R(9),R(3));
    R(2)=pop(s,ram);R(16)=pop(s,ram);set_fpscr(s,R(2));
    R(9)=pop(s,ram);R(10)=pop(s,ram);R(11)=pop(s,ram);
    R(12)=pop(s,ram);R(13)=pop(s,ram);R(14)=pop(s,ram);
    s->pc=R(16);s->task_driver=scope.previous;return ram->oob==0;
failed:
    s->task_driver=scope.previous;return 0;
}

/* 0x8c053d7c: the file subsystem polls its registered worker context through
 * this literal-loaded tail call. Preserve the original incoming PR. */
int vf3_task_driver_poll_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    R(3)=0x0c04bd62;R(2)=0x0c1b9608;R(4)=READ(R(2));
    return vf3_task_driver_c(s,ram,0x0c000000u);
}

/* The file subsystem's real one-tick yield, 0x0c053d8c -> 0x0c04bd5e
 * -> 0x0c04bd20. Both SDK context operations still execute their original
 * C semantics; longjmp only unwinds the host C calls that the SH-4 stack
 * restore has made obsolete. */
int vf3_task_driver_yield_c(uint32_t entry,vf3_matrix_state *s,const vf3_ram_map *ram)
{
    struct vf3_task_driver_scope *scope=s->task_driver;
    if(entry==0x0c053d8c){R(2)=0x0c04bd5e;R(4)=1;}
    else if(entry==0x0c04bd5e)R(4)=1;
    push(s,ram,R(14));condition(s,(int32_t)R(4)>=0);
    R(14)=0x0c1b2088;R(0)=0x18c0;R(3)=READ(R(14));
    push(s,ram,R(16));R(2)=READ(R(3)+R(0));
    if(R(17)&1u){R(0)=0x134;R(1)=READ(R(14));R(1)=READ(R(1)+R(0));R(1)+=R(4);}
    else R(1)=0x7fffffff;
    WRITE(R(2)+20,R(1));R(0)=0x18c0;R(4)=READ(R(14));
    R(3)=0x0c0544c8;R(4)=READ(R(4)+R(0));R(4)+=24;
    if(!call(s,ram,R(3),0x0c04bd4a))return 0;
    if(s->pc!=0x0c04bd4a)return vf3_matrix_family(s->pc,s,ram);
    condition(s,R(0)==0);
    if(R(17)&1u){
        R(3)=0x0c054454;R(5)=1;R(4)=READ(R(14));R(4)+=4;
        if(!call(s,ram,R(3),0x0c04bd58))return 0;
        if(scope && s->pc==scope->resume_pc && R(15)==scope->resume_sp)
            longjmp(scope->jump,1);
        if(s->pc!=0x0c04bd58)return vf3_matrix_family(s->pc,s,ram);
    }
    R(16)=pop(s,ram);R(14)=pop(s,ram);s->pc=R(16);
    return ram->oob==0;
}

/* The actual job return target marks its record for cleanup, then yields
 * immediately through the same SDK continuation protocol. */
int vf3_task_driver_retire_c(vf3_matrix_state *s,const vf3_ram_map *ram)
{
    R(2)=0x0c1b2088;R(0)=0x18c0;R(3)=READ(R(2));
    R(1)=READ(R(3)+R(0));R(3)=3;WRITE(R(1)+12,R(3));R(4)=0;
    return vf3_task_driver_yield_c(0x0c04bd20u,s,ram);
}
