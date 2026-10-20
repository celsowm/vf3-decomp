/* Matrix stack, affine transforms and register-bank adapters. This source
 * uses matrix/vector loops; it neither decodes opcodes nor executes the ROM. */
#include "fight/matrix_family.h"
#include "fight/family_hooks.h"
int vf3_clip_strip_c(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_clip_strip_writers_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_clip_strip_writers_adapter_contains(uint32_t);
int vf3_selection_unlock_c(vf3_matrix_state*,const vf3_ram_map*);
int vf3_scene_input_transition_c(vf3_matrix_state*,const vf3_ram_map*);
int vf3_scene_replay_transition_c(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_replay_pair_reset_c(vf3_matrix_state*,const vf3_ram_map*);
int vf3_replay_action_reset_c(vf3_matrix_state*,const vf3_ram_map*);
int vf3_replay_orientation_reset_c(vf3_matrix_state*,const vf3_ram_map*);
int vf3_scene_round_decision_c(vf3_matrix_state*,const vf3_ram_map*);
int vf3_result_statistics_c(vf3_matrix_state*,const vf3_ram_map*);
int vf3_result_record_entry_c(vf3_matrix_state*,const vf3_ram_map*);
int vf3_tenpp_survey_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_tenpp_survey_adapter_contains(uint32_t);
int vf3_tenpp_leaf_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_tenpp_leaf_adapter_contains(uint32_t);
int vf3_tenpp_complex_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_tenpp_complex_adapter_contains(uint32_t);
int vf3_tenpp_acceptance_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_tenpp_acceptance_adapter_contains(uint32_t);
int vf3_tenpp_planned_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_tenpp_planned_adapter_contains(uint32_t);
int vf3_tenpp_large_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_tenpp_large_adapter_contains(uint32_t);
int vf3_tenpp_recovery_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_tenpp_recovery_adapter_contains(uint32_t);
int vf3_tenpp_expanded_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_tenpp_expanded_adapter_contains(uint32_t);
int vf3_sweep_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_sweep_adapter_contains(uint32_t);
int vf3_advance_closure_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_advance_closure_adapter_contains(uint32_t);
int vf3_advance_worker_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_advance_worker_adapter_contains(uint32_t);
int vf3_advance_leaf_ranked_more_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_advance_leaf_ranked_more_adapter_contains(uint32_t);
int vf3_advance_leaf_ranked_remainder_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_advance_leaf_ranked_remainder_adapter_contains(uint32_t);
int vf3_advance_05b20e_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_advance_05b20e_adapter_contains(uint32_t);
int vf3_advance_dynamic_06129c(vf3_matrix_state*,const vf3_ram_map*);
int vf3_advance_resource_descriptor(vf3_matrix_state*,const vf3_ram_map*);
int vf3_advance_descriptor_flags(vf3_matrix_state*,const vf3_ram_map*);
int vf3_advance_scene_entry_reset(vf3_matrix_state*,const vf3_ram_map*);
int vf3_advance_scene_commands(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_advance_scene_selector(vf3_matrix_state*,const vf3_ram_map*);
int vf3_advance_static_helpers(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_advance_controller_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_advance_controller_adapter_contains(uint32_t);
int vf3_advance_render_helpers(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_advance_vector_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_advance_vector_adapter_contains(uint32_t);
int vf3_advance_record_render(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_advance_config_editors(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_advance_config_editors_contains(uint32_t);
int vf3_advance_client_wrappers(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_advance_state_helpers(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_continuation_input_controls(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_command_encoders(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_audio_channels_c(vf3_matrix_state*,const vf3_ram_map*);
int vf3_audio_submission_c(vf3_matrix_state*,const vf3_ram_map*);
int vf3_audio_style_c(vf3_matrix_state*,const vf3_ram_map*);
int vf3_audio_actor_clear_c(vf3_matrix_state*,const vf3_ram_map*);
int vf3_audio_encoder_c(vf3_matrix_state*,const vf3_ram_map*,uint32_t,int);
int vf3_audio_request_c(vf3_matrix_state*,const vf3_ram_map*,uint32_t,int);
int vf3_audio_input_c(vf3_matrix_state*,const vf3_ram_map*,uint32_t);
int vf3_audio_fight_c(vf3_matrix_state*,const vf3_ram_map*,uint32_t);
int vf3_motion_frame_c(vf3_matrix_state*,const vf3_ram_map*,uint32_t);
int vf3_task_driver_c(vf3_matrix_state*,const vf3_ram_map*,uint32_t);
int vf3_task_driver_poll_c(vf3_matrix_state*,const vf3_ram_map*);
int vf3_task_driver_yield_c(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_task_driver_restore_c(vf3_matrix_state*,const vf3_ram_map*);
int vf3_task_driver_retire_c(vf3_matrix_state*,const vf3_ram_map*);
int vf3_task_callback_select(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_resource_ranges(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_motion_flag_command(vf3_matrix_state*,const vf3_ram_map*);
int vf3_percentage_aux_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_motion_group_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_motion_group_adapter_contains(uint32_t);
int vf3_motion_initialize_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_motion_initialize_adapter_contains(uint32_t);
int vf3_motion_style_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_motion_style_adapter_contains(uint32_t);
int vf3_percentage_aux_adapter_contains(uint32_t);
int vf3_percentage_family_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_percentage_family_adapter_contains(uint32_t);
int vf3_scene_indicator(vf3_matrix_state*,const vf3_ram_map*);
int vf3_random_fraction(vf3_matrix_state*,const vf3_ram_map*);
int vf3_resource_index_reset(vf3_matrix_state*,const vf3_ram_map*);
int vf3_texture_storage(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_texture_size_class(vf3_matrix_state*,const vf3_ram_map*);
int vf3_model_render_fields(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_vertex_weight_curve(vf3_matrix_state*,const vf3_ram_map*);
int vf3_weighted_vertex(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_record_pool_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_record_pool_adapter_contains(uint32_t);
int vf3_indexed_vertex_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_indexed_vertex_adapter_contains(uint32_t);
int vf3_object_pool_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_object_pool_adapter_contains(uint32_t);
int vf3_motion_model_selection(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_script_scale_command(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_script_position_command(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_motion_descriptor_command(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_task_text_command(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_target_family_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_target_family_adapter_contains(uint32_t);
int vf3_target_extra_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_target_extra_adapter_contains(uint32_t);
int vf3_target_broad_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_target_broad_adapter_contains(uint32_t);
int vf3_target_extended_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_target_extended_adapter_contains(uint32_t);
int vf3_target_closure_step(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_target_closure_step_contains(uint32_t);
int vf3_target_scene_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_target_scene_adapter_contains(uint32_t);
int vf3_target_remaining_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_target_remaining_adapter_contains(uint32_t);
int vf3_target_retained_scene_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_target_retained_scene_adapter_contains(uint32_t);
int vf3_target_dependency_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_target_dependency_adapter_contains(uint32_t);
int vf3_target_record_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_target_record_adapter_contains(uint32_t);
int vf3_target_configuration_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_target_configuration_adapter_contains(uint32_t);
int vf3_target_action_selector_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_target_action_selector_adapter_contains(uint32_t);
int vf3_continuation_allocator_helpers(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_continuation_matrix_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_continuation_matrix_adapter_contains(uint32_t);
int vf3_advance_small_tail_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_advance_small_tail_adapter_contains(uint32_t);
int vf3_advance_medium_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_advance_medium_adapter_contains(uint32_t);
int vf3_advance_client_helper_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_advance_client_helper_adapter_contains(uint32_t);
int vf3_advance_branch_adapter(uint32_t,vf3_matrix_state*,const vf3_ram_map*);
int vf3_advance_branch_adapter_contains(uint32_t);
#include "fight/sh4_matrix.h"
#include "fight/sh4_fpu.h"
#include "fight/fpu_tz.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define rd vf3_matrix_read
#define wr vf3_matrix_write
#define load vf3_matrix_load
#define store vf3_matrix_store
#define mov vf3_matrix_move
#define swap_banks vf3_matrix_swap
#define R(n) s->v[n]
#define FR(n) s->v[21+(n)]
#define XF(n) s->v[37+(n)]
#define FPSCR s->v[18]
#define FPUL s->v[53]
static void t(vf3_matrix_state*s,int v) { R(17)=(R(17)&~1u)|(v!=0); }
static struct { uint8_t *data; uint32_t len; int tried; } vf3_image;
static void vf3_load_image(void) {
    if(vf3_image.tried) return;
    vf3_image.tried=1;
    const char *path=getenv("VF3_IMAGE"); if(!path) path="extract/gamedata/1ST_READ.BIN";
    FILE *f=fopen(path,"rb");
    if(!f) return;
    fseek(f,0,SEEK_END); long n=ftell(f); fseek(f,0,SEEK_SET);
    if(n>0) {
        vf3_image.data=(uint8_t*)malloc((size_t)n);
        if(vf3_image.data && fread(vf3_image.data,1,(size_t)n,f)==(size_t)n)
            vf3_image.len=(uint32_t)n;
        else { free(vf3_image.data); vf3_image.data=NULL; }
    }
    fclose(f);
}
static uint32_t vf3_image_byte(uint32_t addr) {
    /* Identity-mapped retail image (docs/re/image_identity.md): serve bytes
     * of the loaded 1ST_READ window for reads the corpus windows truncated.
     * Runtime-writeable state beyond the image end is never served here. */
    if(!vf3_image.tried) vf3_load_image();
    if(vf3_image.data && addr>=0x0c010000u && addr-0x0c010000u<vf3_image.len)
        return vf3_image.data[addr-0x0c010000u];
    return 0x100u;  /* sentinel: not image-backed */
}
uint32_t vf3_matrix_read(const vf3_ram_map *ram,uint32_t addr,unsigned size) {
    uint32_t value=0;
    addr&=0x1FFFFFFFu;
    /* Area 3 mirrors the 16 MiB RAM four times across 0x0C..0x0F. */
    if(addr>=0x0c000000u && addr<0x10000000u)
        addr=0x0c000000u|(addr&0x00ffffffu);
    if((addr<0x0c000000u || addr>=0x0d000000u) && ram->device_read)
        return ram->device_read(ram->device_context,addr,size);
    for(unsigned j=0;j<size;++j) {
        int found=0;
        for(int i=0;i<ram->n;++i) if(addr+j>=ram->wins[i].base && addr+j-ram->wins[i].base<ram->wins[i].len) {
            value|=(uint32_t)ram->wins[i].data[addr+j-ram->wins[i].base]<<(8*j); found=1; break;
        }
        if(!found) {
            uint32_t b=vf3_image_byte(addr+j);
            if(b!=0x100u) { value|=b<<(8*j); continue; }
            if(!ram->oob && getenv("VF3_REPLAY_OOB"))
                fprintf(stderr,"uncaptured read: %08x/%u\n",addr,size);
            ++((vf3_ram_map*)ram)->oob;
        }
    }
    return value;
}
/* SH-4 store queues: 32-bit stores to 0xE0000000..0xE3FFFFFF fill SQ0/SQ1 (address bit 5);
 * PREF @Rn on such an address bursts the 32 bytes to (QACRn.AREA<<26)|(Rn&0x03FFFFE0), which
 * is how the game fills its geometry buffers and hands display lists to the TA. The stores
 * stay visible to the device hook so existing device logs are unchanged. */
static uint32_t vf3_sq_buf[2][8], vf3_sq_qacr[2];
int vf3_sq_model;
void vf3_matrix_pref(const vf3_ram_map *ram,uint32_t a) {
    unsigned n=(a>>5)&1u;
    if(!vf3_sq_model) return;
    /* chained ticks restart from a capture whose QACR predates the game's own retarget; TICK_QACR0/1 (the same
     * switches the oracle takes) pin the area so both sides burst to the same place */
    static int forced[2]={-2,-2};
    if(forced[n]==-2) { const char *e=getenv(n?"TICK_QACR1":"TICK_QACR0"); forced[n]=e?(int)(strtoul(e,0,0)&0x1Cu):-1; }
    uint32_t dest=((forced[n]>=0?(uint32_t)forced[n]:vf3_sq_qacr[n])<<24)|(a&0x03FFFFE0u);
    for(unsigned i=0;i<8;++i) vf3_matrix_write(ram,dest+4*i,vf3_sq_buf[n][i],4);
}
void vf3_matrix_write(const vf3_ram_map *ram,uint32_t addr,uint32_t value,unsigned size) {
    if((addr&0xFC000000u)==0xE0000000u && size==4) vf3_sq_buf[(addr>>5)&1u][(addr>>2)&7u]=value;
    addr&=0x1FFFFFFFu;
    if(addr==0x1F000038u || addr==0x1F00003Cu) vf3_sq_qacr[(addr>>2)&1u]=value&0x1Cu;
    if(addr>=0x0c000000u && addr<0x10000000u)
        addr=0x0c000000u|(addr&0x00ffffffu);
    if((addr<0x0c000000u || addr>=0x0d000000u) && ram->device_write) {
        ram->device_write(ram->device_context,addr,size,value); return;
    }
    for(unsigned j=0;j<size;++j) {
        int found=0;
        for(int i=0;i<ram->n;++i) if(addr+j>=ram->wins[i].base && addr+j-ram->wins[i].base<ram->wins[i].len) {
            ram->wins[i].data[addr+j-ram->wins[i].base]=(uint8_t)(value>>(8*j)); found=1; break;
        }
        if(!found) {
            if(!ram->oob && getenv("VF3_REPLAY_OOB"))
                fprintf(stderr,"uncaptured write: %08x/%u=%08x\n",addr,size,value);
            ++((vf3_ram_map*)ram)->oob;
        }
    }
}
void vf3_matrix_swap(vf3_matrix_state*s) {
    for(unsigned i=0;i<16;++i) { uint32_t a=FR(i); FR(i)=XF(i); XF(i)=a; }
    FPSCR^=0x200000u; /* FR is bit 21; DN is bit 18 on the SH-4. */
}
static unsigned width(vf3_matrix_state*s) { return (FPSCR&0x100000u)?8:4; }
static uint32_t *bank(vf3_matrix_state*s,unsigned n) {
    if(width(s)==4) return &FR(n);
    return (n&1)?&XF(n&~1u):&FR(n&~1u);
}
void vf3_matrix_load(vf3_matrix_state*s,const vf3_ram_map*ram,unsigned reg,uint32_t addr) {
    uint32_t *p=bank(s,reg); unsigned n=width(s)/4;
    for(unsigned i=0;i<n;++i) p[i]=vf3_matrix_read(ram,addr+4*i,4);
}
void vf3_matrix_store(vf3_matrix_state*s,const vf3_ram_map*ram,unsigned reg,uint32_t addr) {
    uint32_t *p=bank(s,reg); unsigned n=width(s)/4;
    for(unsigned i=0;i<n;++i) vf3_matrix_write(ram,addr+4*i,p[i],4);
}
void vf3_matrix_move(vf3_matrix_state*s,unsigned dst,unsigned src) {
    uint32_t temp[2]; unsigned n=width(s);
    memcpy(temp,bank(s,src),n); memcpy(bank(s,dst),temp,n);
}
static int transform(vf3_matrix_state*s,unsigned base) {
    return vf3_fpu_ftrv(&XF(0),&FR(base),FPSCR,&FR(base));
}
static void push(vf3_matrix_state*s,const vf3_ram_map*ram,uint32_t value) { R(15)-=4; wr(ram,R(15),value,4); }
static uint32_t pop(vf3_matrix_state*s,const vf3_ram_map*ram) { uint32_t a=rd(ram,R(15),4); R(15)+=4; return a; }
int vf3_controller_merge_c(vf3_matrix_state *,const vf3_ram_map *,uint32_t);
int vf3_controller_port_c(vf3_matrix_state *,const vf3_ram_map *,uint32_t);
int vf3_controller_secondary_c(vf3_matrix_state *,const vf3_ram_map *,uint32_t);
int vf3_geometry_angles_c(vf3_matrix_state *,const vf3_ram_map *,uint32_t);
int vf3_angle_wrap_c(vf3_matrix_state *,const vf3_ram_map *,uint32_t);
int vf3_packed_direction_c(vf3_matrix_state *,const vf3_ram_map *,uint32_t);
int vf3_clipped_vertices_c(vf3_matrix_state *,const vf3_ram_map *,uint32_t);
int vf3_project_point_c(vf3_matrix_state *,const vf3_ram_map *,uint32_t);
int vf3_polygon_hit_c(vf3_matrix_state *,const vf3_ram_map *,uint32_t);
int vf3_scene_insert_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_contact_frame_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_contact_init_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_contact_history_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_round_score_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_round_transition_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_settings_menu_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_render_lanes_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_replay_history_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_history_scan_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_replay_callback_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_replay_initializer_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_replay_interpolate_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_replay_round_clear_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_clip_triangle_c(uint32_t,vf3_matrix_state *,const vf3_ram_map *);
int vf3_plain_weight_vertex_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_clip_attributes_c(uint32_t,vf3_matrix_state *,const vf3_ram_map *);
int vf3_round_clock_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_scene_replay_flow_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_actor_history_run_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_scene_end_predicate_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_scene_secondary_dispatch_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_round_retire_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_scene_activate_predicate_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_replay_ready_marker_c(uint32_t,vf3_matrix_state *,const vf3_ram_map *);
int vf3_replay_completion_status_c(uint32_t,vf3_matrix_state *,const vf3_ram_map *);
int vf3_replay_wait_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_timed_boundary_effect_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_list_interpolate_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_list_move_head_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_cubic_channel_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_geometry_callback_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_replay_record_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_history_record_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_contact_history_helpers_c(uint32_t,vf3_matrix_state *,const vf3_ram_map *);
int vf3_aggregate_frame_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_radial_wrapper_c(vf3_matrix_state *,const vf3_ram_map *,uint32_t);
int vf3_ring_bound_c(vf3_matrix_state *,const vf3_ram_map *,uint32_t);
int vf3_radial_bound_c(vf3_matrix_state *,const vf3_ram_map *,uint32_t);
int vf3_vector_sum_c(vf3_matrix_state *,const vf3_ram_map *,uint32_t);
int vf3_geometry_intersections_c(uint32_t,vf3_matrix_state *,const vf3_ram_map *,uint32_t);
int vf3_actor_table_apply_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_actor_table_family_c(uint32_t,vf3_matrix_state *,const vf3_ram_map *);
int vf3_actor_table_literal_c(uint32_t,vf3_matrix_state *,const vf3_ram_map *);
int vf3_motion_settle_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_command_retire_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_event_admission_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_size_profile_init_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_profile_clear_c(vf3_matrix_state *,const vf3_ram_map *);
int vf3_actor_profile_pair_c(vf3_matrix_state *,const vf3_ram_map *);
vf3_family_hook_fn vf3_family_override, vf3_family_missing, vf3_family_fail;
vf3_family_obs_fn vf3_family_enter, vf3_family_leave;
static int vf3_matrix_family_core(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
    uint32_t audio_alias=(entry&0x80000000u)?0x8c000000u:0x0c000000u;
    const uint32_t queue=0x0C19D2E4u;
    entry&=0x1FFFFFFFu;
    if(!vf3_fpu_supported(FPSCR)) return 0;
    /* A jsr through a null pointer traps on the SH-4.  The emulator records the
     * trap as the end of the specimen, so the C side has to treat the null
     * target as "the call landed and nothing else happened" instead of an
     * unimplemented helper (docs/re/remaining_work_plan.md, T1.5). */
    if(entry==0u) return 1;
    if(entry==0x0c085ca4u) return vf3_profile_clear_c(s,ram);
    if(entry==0x0c095178u) return vf3_actor_profile_pair_c(s,ram);
    if(entry==0x0c0885c4u) return vf3_motion_settle_c(s,ram);
    if(entry==0x0c07b6f4u) return vf3_command_retire_c(s,ram);
    if(entry==0x0c08c054u) return vf3_event_admission_c(s,ram);
    if(entry==0x0c0860c2u) return vf3_size_profile_init_c(s,ram);
    switch(entry) {
    case 0x0c0a4664u: case 0x0c0a4d3cu: case 0x0c0a5758u:
    case 0x0c0a5b50u: case 0x0c0a5d98u: case 0x0c0a3e1eu:
    case 0x0c0a52ecu: case 0x0c0a4410u: case 0x0c0a423au:
    case 0x0c0a4b5eu: case 0x0c0a61fau: case 0x0c0a40acu:
    case 0x0c0a486eu: case 0x0c0a49e2u: case 0x0c0a4efcu:
    case 0x0c0a5068u: case 0x0c0a5f52u: case 0x0c0a609au:
        return vf3_actor_table_literal_c(entry,s,ram);
    default: break;
    }
    if(entry==0x0c0a575cu) return vf3_actor_table_apply_c(s,ram);
    if(entry==0x0c0a3242u||entry==0x0c0a3504u||entry==0x0c0a38aeu||entry==0x0c0a3af2u)
        return vf3_actor_table_family_c(entry,s,ram);
    if(entry==0x0c0993e0u) return vf3_scene_input_transition_c(s,ram);
    if(entry==0x0c099540u||entry==0x0c099560u) return vf3_scene_replay_transition_c(entry,s,ram);
    if(entry==0x0c0a91dau) return vf3_replay_pair_reset_c(s,ram);
    if(entry==0x0c0a92c8u) return vf3_replay_action_reset_c(s,ram);
    if(entry==0x0c0a9444u) return vf3_replay_orientation_reset_c(s,ram);
    if(entry==0x0c098c62u) return vf3_scene_round_decision_c(s,ram);
    if(entry==0x0c09d138u) return vf3_result_statistics_c(s,ram);
    if(entry==0x0c0698ecu) return vf3_result_record_entry_c(s,ram);
    if(entry==0x0c0c3210u) return vf3_selection_unlock_c(s,ram);
    if(entry==0x0c08a61cu) return vf3_scene_indicator(s,ram);
    if(entry==0x0c0c9d04u) return vf3_random_fraction(s,ram);
    if(entry==0x0c045e4eu || entry==0x0c0801deu)
        return vf3_advance_client_wrappers(entry,s,ram);
    if(entry==0x0c07abf8u) return vf3_resource_index_reset(s,ram);
    if(entry==0x0c0a8d58u || entry==0x0c0a8d5cu)
        return vf3_motion_descriptor_command(entry,s,ram);
    if(entry==0x0c0a94d0u) return vf3_motion_frame_c(s,ram,audio_alias);
    if(entry==0x0c09af6cu) return vf3_controller_merge_c(s,ram,audio_alias);
    if(entry==0x0c09b006u) return vf3_controller_port_c(s,ram,audio_alias);
    if(entry==0x0c09afc0u) return vf3_controller_secondary_c(s,ram,audio_alias);
    if(entry==0x0c0ca8c0u) return vf3_geometry_angles_c(s,ram,audio_alias);
    if(entry==0x0c09f6fcu) return vf3_angle_wrap_c(s,ram,audio_alias);
    if(entry==0x0c05865cu) return vf3_packed_direction_c(s,ram,audio_alias);
    if(entry==0x0c058a5cu) return vf3_clipped_vertices_c(s,ram,audio_alias);
    if(entry==0x0c03d9b0u) return vf3_project_point_c(s,ram,audio_alias);
    if(entry==0x0c06e056u) return vf3_polygon_hit_c(s,ram,audio_alias);
    if(entry==0x0c09fefeu) return vf3_scene_insert_c(s,ram);
    if(entry==0x0c0a0aecu) return vf3_contact_frame_c(s,ram);
    if(entry==0x0c0a07e4u) return vf3_contact_init_c(s,ram);
    if(entry==0x0c0c0bf4u) return vf3_contact_history_c(s,ram);
    if(entry==0x0c0a7be2u) return vf3_round_score_c(s,ram);
    if(entry==0x0c09a0a8u) return vf3_round_transition_c(s,ram);
    if(entry==0x0c0c95f4u) return vf3_settings_menu_c(s,ram);
    if(entry==0x0c05d424u) return vf3_render_lanes_c(s,ram);
    if(entry==0x0c0a87fcu) return vf3_replay_history_c(s,ram);
    if(entry==0x0c0a86acu) return vf3_history_scan_c(s,ram);
    if(entry==0x0c0a8e18u) return vf3_replay_callback_c(s,ram);
    if(entry==0x0c0a8370u) return vf3_replay_initializer_c(s,ram);
    if(entry==0x0c0a8f8cu) return vf3_replay_interpolate_c(s,ram);
    if(entry==0x0c098b3cu) return vf3_round_clock_c(s,ram);
    if(entry==0x0c099194u) return vf3_scene_replay_flow_c(s,ram);
    if(entry==0x0c091eb8u) return vf3_actor_history_run_c(s,ram);
    if(entry==0x0c097ff4u) return vf3_scene_end_predicate_c(s,ram);
    if(entry==0x0c0a8908u) return vf3_replay_round_clear_c(s,ram);
    if(entry==0x0c096d3cu) return vf3_scene_secondary_dispatch_c(s,ram);
    if(entry==0x0c09705eu) return vf3_round_retire_c(s,ram);
    if(entry==0x0c096d5eu) return vf3_scene_activate_predicate_c(s,ram);
    if(entry==0x0c0a9244u||entry==0x0c0a926au) return vf3_replay_ready_marker_c(entry,s,ram);
    if(entry==0x0c0994fau||entry==0x0c099504u) return vf3_replay_completion_status_c(entry,s,ram);
    if(entry==0x0c0993e0u) return vf3_replay_wait_c(s,ram);
    if(entry==0x0c08acc0u) return vf3_timed_boundary_effect_c(s,ram);
    if(entry==0x0c08f632u) return vf3_list_interpolate_c(s,ram);
    if(entry==0x0c08f4aeu) return vf3_list_move_head_c(s,ram);
    if(entry==0x0c08f582u) return vf3_cubic_channel_c(s,ram);
    if(entry==0x0c087e04u) return vf3_geometry_callback_c(s,ram);
    if(entry==0x0c0570e0u || entry==0x0c057480u || entry==0x0c057860u ||
       entry==0x0c057c60u || entry==0x0c057fa0u)
        return vf3_clip_strip_c(entry,s,ram);
    if(vf3_clip_strip_writers_adapter_contains(entry))
        return vf3_clip_strip_writers_adapter(entry,s,ram);
    if(entry==0x0c05152cu||entry==0x0c051918u||entry==0x0c051c2cu||entry==0x0c051f50u||
       entry==0x0c05228cu||entry==0x0c0525c0u||entry==0x0c05291cu||entry==0x0c052c34u)
        return vf3_clip_triangle_c(entry,s,ram);
    if(entry==0x0c0a9036u) return vf3_replay_record_c(s,ram);
    if(entry==0x0c0a83c2u) return vf3_history_record_c(s,ram);
    if(entry==0x0c0c0ebau||entry==0x0c0c0f60u) return vf3_contact_history_helpers_c(entry,s,ram);
    if(entry==0x0c0a6dbau) return vf3_aggregate_frame_c(s,ram);
    if(entry==0x0c0cb65au) return vf3_radial_wrapper_c(s,ram,audio_alias);
    if(entry==0x0c0cb51eu) return vf3_ring_bound_c(s,ram,audio_alias);
    if(entry==0x0c0cb67au) return vf3_radial_bound_c(s,ram,audio_alias);
    if(entry==0x0c0a6ff8u) return vf3_vector_sum_c(s,ram,audio_alias);
    if(entry==0x0c0ca838u || entry==0x0c0ca894u)
        return vf3_geometry_intersections_c(entry,s,ram,audio_alias);
    /* Resource workers execute through the uncached 0x0c alias. Capture
     * inventory keys use 0x8c even for these original 0x0c invocations. */
    if(entry==0x0c04bd62u) return vf3_task_driver_c(s,ram,0x0c000000u);
    if(entry==0x0c053d7cu) return vf3_task_driver_poll_c(s,ram);
    if(s->task_driver && entry==0x0c054454u)
        return vf3_task_driver_restore_c(s,ram);
    if(s->task_driver && entry==0x0c04bc52u)
        return vf3_task_driver_retire_c(s,ram);
    if(s->task_driver && (entry==0x0c053d8cu || entry==0x0c04bd5eu || entry==0x0c04bd20u))
        return vf3_task_driver_yield_c(entry,s,ram);
    if(entry==0x0c0af37cu || entry==0x0c0af38cu)
        return vf3_script_position_command(entry,s,ram);
    if(entry==0x0c0af448u || entry==0x0c0af44eu || entry==0x0c0af608u || entry==0x0c0af610u)
        return vf3_script_scale_command(entry,s,ram);
    if(entry==0x0c05f28au || entry==0x0c05f294u)
        return vf3_texture_storage(entry,s,ram);
    if(entry==0x0c05f0b8u) return vf3_texture_size_class(s,ram);
    if(entry==0x0c09517au || entry==0x0c09518cu)
        return vf3_motion_model_selection(entry,s,ram);
    if(entry==0x0c09528cu || entry==0x0c0952a4u)
        return vf3_model_render_fields(entry,s,ram);
    if(entry==0x0c056c66u) return vf3_vertex_weight_curve(s,ram);
    if(entry==0x0c051b58u) return vf3_plain_weight_vertex_c(s,ram);
    if(entry==0x0c0517a0u||entry==0x0c0517b8u||entry==0x0c05174cu||
       entry==0x0c051ea0u||entry==0x0c051ecau||entry==0x0c051e4cu||
       entry==0x0c052518u||entry==0x0c052540u||entry==0x0c0524acu||
       entry==0x0c052b94u||entry==0x0c052bbau||entry==0x0c052b3cu||
       entry==0x0c052eb4u||entry==0x0c052ecau||entry==0x0c052e54u)
        return vf3_clip_attributes_c(entry,s,ram);
    if(entry==0x0c051b74u || entry==0x0c0521acu || entry==0x0c052824u)
        return vf3_weighted_vertex(entry,s,ram);
    if(vf3_record_pool_adapter_contains(entry))
        return vf3_record_pool_adapter(entry,s,ram);
    if(vf3_indexed_vertex_adapter_contains(entry))
        return vf3_indexed_vertex_adapter(entry,s,ram);
    if(vf3_object_pool_adapter_contains(entry))
        return vf3_object_pool_adapter(entry,s,ram);
    if(entry==0x0c059400u) return vf3_task_callback_select(entry,s,ram);
    if(entry==0x0c0af1a4u) return vf3_motion_flag_command(s,ram);
    if(entry==0x0c05caceu || entry==0x0c061ba8u || entry==0x0c05c90eu)
        return vf3_resource_ranges(entry,s,ram);
    if(entry==0x0c06c52au || entry==0x0c06cea2u)
        return vf3_task_text_command(entry,s,ram);
    if(vf3_motion_style_adapter_contains(entry))
        return vf3_motion_style_adapter(entry,s,ram);
    if(vf3_motion_initialize_adapter_contains(entry))
        return vf3_motion_initialize_adapter(entry,s,ram);
    if(vf3_motion_group_adapter_contains(entry))
        return vf3_motion_group_adapter(entry,s,ram);
    if(vf3_percentage_aux_adapter_contains(entry))
        return vf3_percentage_aux_adapter(entry,s,ram);
    if(vf3_percentage_family_adapter_contains(entry))
        return vf3_percentage_family_adapter(entry,s,ram);
    switch(entry) {
    case 0x0c040fa4: return vf3_audio_channels_c(s,ram);
    case 0x0c0c5d86: return vf3_audio_submission_c(s,ram);
    case 0x0c0ca05c: return vf3_audio_style_c(s,ram);
    case 0x0c098040: return vf3_audio_actor_clear_c(s,ram);
    case 0x0c040b7c: case 0x0c040b7e:
        return vf3_audio_encoder_c(s,ram,audio_alias,entry==0x0c040b7c);
    case 0x0c0c5c94: case 0x0c0c5ca2:
        return vf3_audio_request_c(s,ram,audio_alias,entry==0x0c0c5c94);
    case 0x0c0c9f54: return vf3_audio_input_c(s,ram,audio_alias);
    case 0x0c099060: return vf3_audio_fight_c(s,ram,audio_alias);
    case 0x0c040f1e:
    case 0x0c040c90: case 0x0c040c92: case 0x0c040d1c: case 0x0c040d20:
    case 0x0c040e24: case 0x0c040e28:
    case 0x0c040ec2: case 0x0c040ec6:
    case 0x0c041d04: case 0x0c041d06: case 0x0c041d7c: case 0x0c041d7e:
    case 0x0c041de0: case 0x0c041de2: case 0x0c041e58: case 0x0c041e5a:
    case 0x0c041ebc: case 0x0c041ebe: return vf3_command_encoders(entry,s,ram);
    default: break;
    }
    if(vf3_target_family_adapter_contains(entry))
        return vf3_target_family_adapter(entry,s,ram);
    if(vf3_target_extra_adapter_contains(entry))
        return vf3_target_extra_adapter(entry,s,ram);
    if(vf3_target_broad_adapter_contains(entry))
        return vf3_target_broad_adapter(entry,s,ram);
    if(vf3_target_extended_adapter_contains(entry))
        return vf3_target_extended_adapter(entry,s,ram);
    if(vf3_target_closure_step_contains(entry))
        return vf3_target_closure_step(entry,s,ram);
    if(vf3_target_scene_adapter_contains(entry))
        return vf3_target_scene_adapter(entry,s,ram);
    if(vf3_target_remaining_adapter_contains(entry))
        return vf3_target_remaining_adapter(entry,s,ram);
    if(vf3_target_retained_scene_adapter_contains(entry))
        return vf3_target_retained_scene_adapter(entry,s,ram);
    if(vf3_target_dependency_adapter_contains(entry))
        return vf3_target_dependency_adapter(entry,s,ram);
    if(vf3_target_record_adapter_contains(entry))
        return vf3_target_record_adapter(entry,s,ram);
    if(vf3_target_configuration_adapter_contains(entry))
        return vf3_target_configuration_adapter(entry,s,ram);
    if(vf3_target_action_selector_adapter_contains(entry))
        return vf3_target_action_selector_adapter(entry,s,ram);
    if(vf3_advance_controller_adapter_contains(entry))
        return vf3_advance_controller_adapter(entry,s,ram);
    if(vf3_advance_vector_adapter_contains(entry))
        return vf3_advance_vector_adapter(entry,s,ram);
    if(entry==0x0c076aa8 || entry==0x0c042fdc || entry==0x0c076b3c)
        return vf3_advance_state_helpers(entry,s,ram);
    if(entry==0x0c05d2d0 || entry==0x0c05d2dc)
        return vf3_continuation_input_controls(entry,s,ram);
    if(entry==0x0c062490 || entry==0x0c0624ba || entry==0x0c062524)
        return vf3_continuation_allocator_helpers(entry,s,ram);
    if(vf3_continuation_matrix_adapter_contains(entry))
        return vf3_continuation_matrix_adapter(entry,s,ram);
    if(vf3_advance_config_editors_contains(entry))
        return vf3_advance_config_editors(entry,s,ram);
    if(vf3_advance_client_helper_adapter_contains(entry))
        return vf3_advance_client_helper_adapter(entry,s,ram);
    if(vf3_advance_branch_adapter_contains(entry))
        return vf3_advance_branch_adapter(entry,s,ram);
    if(vf3_advance_medium_adapter_contains(entry))
        return vf3_advance_medium_adapter(entry,s,ram);
    if(vf3_advance_small_tail_adapter_contains(entry))
        return vf3_advance_small_tail_adapter(entry,s,ram);
    switch(entry) {
    case 0x0c04ff62: return vf3_advance_client_wrappers(entry,s,ram);
    case 0x0c04667a: case 0x0c0466a8: case 0x0c046730: case 0x0c04675e:
    case 0x0c04678c: case 0x0c046b08: case 0x0c076aec: case 0x0c0c5f52:
        return vf3_advance_client_wrappers(entry,s,ram);
    case 0x0c08559a: case 0x0c086372: case 0x0c087cf2: case 0x0c089fa8:
        return vf3_advance_record_render(entry,s,ram);
    case 0x0c06129c: return vf3_advance_dynamic_06129c(s,ram);
    case 0x0c05c7c6: return vf3_advance_resource_descriptor(s,ram);
    case 0x0c05c128: return vf3_advance_descriptor_flags(s,ram);
    case 0x0c07ad96: return vf3_advance_scene_entry_reset(s,ram);
    case 0x0c09abc4: return vf3_advance_scene_selector(s,ram);
    case 0x0c0a00b6: return vf3_advance_controller_adapter(entry,s,ram);
    case 0x0c06c4a2: case 0x0c08aa64:
        return vf3_advance_render_helpers(entry,s,ram);
    case 0x0c0376a0: case 0x0c03ada4: case 0x0c0469c0:
    case 0x0c04f304: case 0x0c0853a2: case 0x0c09a758:
        return vf3_advance_static_helpers(entry,s,ram);
    case 0x0c03c220: case 0x0c045ce6: case 0x0c045d3e:
    case 0x0c074788: case 0x0c0935ce: case 0x0c0c91ae:
        return vf3_advance_scene_commands(entry,s,ram);
    case 0x0c0cc2d6: return vf3_motion_record_init(s,ram);
    case 0x0c069624: return vf3_fight_angle(s,ram);
    case 0x0c06911c: case 0x0c06912a: return vf3_fight_mesh(entry,s,ram);
    case 0x0C03C940: case 0x0C03C880: case 0x0C03C6C0: {
        uint32_t out[37],xf[16];
        int ok=entry==0x0C03C940?vf3_sh4_c940(s->v,out,&XF(0),xf):
               entry==0x0C03C880?vf3_sh4_c880(s->v,out,&XF(0),xf):vf3_sh4_c6c0(s->v,out,&XF(0),xf);
        if(!ok) return 0;
        FPUL=R(4); memcpy(s->v,out,sizeof(out)); memcpy(&XF(0),xf,sizeof(xf)); break;
    }
    case 0x0C03C4F0: { /* Push current matrix; optionally load the next one. */
        R(3)=queue; swap_banks(s); FPSCR^=0x100000u;
        R(1)=rd(ram,queue+8,4); R(2)=rd(ram,queue,4); R(7)=R(1); R(1)+=64;
        R(6)=(uint32_t)(int32_t)(int16_t)R(2); R(2)=(uint32_t)(int32_t)(int16_t)(R(2)>>16);
        t(s,(int32_t)R(2)>(int32_t)R(6)); R(0)=R(17)&1u;
        for(int i=14;i>=0;i-=2) { R(1)-=width(s); store(s,ram,(unsigned)i,R(1)); }
        R(6)++; R(7)+=64; wr(ram,queue+8,R(7),4);
        t(s,R(4)==0); wr(ram,queue,R(6),2);
        if(!R(4)) FPSCR^=0x100000u;
        else {
            R(1)=4; t(s,(R(4)&4)==0);
            if(R(4)&4) { FPSCR^=0x100000u; for(unsigned i=0;i<16;++i) { load(s,ram,i,R(4)); R(4)+=width(s); } }
            else { for(unsigned i=0;i<16;i+=2) { load(s,ram,i,R(4)); R(4)+=width(s); } FPSCR^=0x100000u; }
        }
        swap_banks(s); break;
    }
    case 0x0C03C4A0: { /* Pop a matrix, clamping the stack cursor to zero. */
        R(3)=queue; t(s,(int32_t)R(4)>0); if(!(R(17)&1)) R(4)=1;
        R(6)=(uint32_t)(int32_t)(int16_t)rd(ram,queue,2);
        FPSCR^=0x100000u; R(2)=(uint32_t)(int32_t)(int16_t)rd(ram,queue+2,2);
        t(s,(int32_t)R(6)>=(int32_t)R(4)); R(6)-=R(4); if(!(R(17)&1)) R(6)=0;
        R(0)=R(17)&1; R(7)=rd(ram,queue+4,4); R(4)=R(6)<<6;
        t(s,(int32_t)R(6)>=(int32_t)R(2)); wr(ram,queue,R(6),2); R(7)+=R(4);
        if(!(R(17)&1)) wr(ram,queue+8,R(7),4);
        for(unsigned i=1;i<16;i+=2) { load(s,ram,i,R(7)); R(7)+=width(s); }
        FPSCR^=0x100000u; break;
    }
    case 0x0C03B620: /* Store current matrix in caller memory or stack slot. */
        t(s,R(4)==0); if(!R(4)) R(4)=rd(ram,queue+8,4);
        R(4)+=64; swap_banks(s);
        for(int i=15;i>=0;--i) { R(4)-=width(s); store(s,ram,(unsigned)i,R(4)); }
        swap_banks(s); R(0)=R(4); break;
    case 0x0C03BD80: /* Load a matrix. */
        t(s,R(4)==0); if(!R(4)) R(4)=rd(ram,queue+8,4);
        swap_banks(s);
        for(unsigned i=0;i<16;++i) { load(s,ram,i,R(4)); R(4)+=width(s); }
        swap_banks(s); break;
    case 0x0C03B530: { /* Copy, load, or store a matrix according to pointers. */
        t(s,R(4)==0); push(s,ram,R(14)); R(14)=R(5);
        if(!R(4)) {
            t(s,R(14)==0);
            if(R(14)) { R(3)=0x0C03BD80u; R(4)=R(14); R(14)=pop(s,ram); return vf3_matrix_family(R(3),s,ram); }
        } else {
            t(s,R(14)==0);
            if(!R(14)) { R(3)=0x0C03B620u; R(14)=pop(s,ram); return vf3_matrix_family(R(3),s,ram); }
            R(5)=R(4); R(4)=16; R(6)=R(14);
            do { load(s,ram,3,R(6)); R(6)+=width(s); --R(4); t(s,R(4)==0); store(s,ram,3,R(5)); R(5)+=4; } while(R(4));
        }
        R(14)=pop(s,ram); break;
    }
    case 0x0C03B450: case 0x0C03B4B0: /* Affine point/direction transform. */
        for(unsigned i=4;i<7;++i) { load(s,ram,i,R(4)); R(4)+=width(s); }
        FR(7)=entry==0x0C03B450?0x3F800000u:0;
        if(!transform(s,4)) return 0;
        R(5)+=12;
        for(int i=6;i>=4;--i) { R(5)-=width(s); store(s,ram,(unsigned)i,R(5)); } break;
    case 0x0C03B820: /* Extract translation. */
        R(4)+=12; swap_banks(s);
        for(int i=14;i>=12;--i) { R(4)-=width(s); store(s,ram,(unsigned)i,R(4)); }
        swap_banks(s); break;
    case 0x0C03CBD0: /* Set translation. */
        swap_banks(s); for(unsigned i=12;i<15;++i) { load(s,ram,i,R(4)); R(4)+=width(s); } swap_banks(s); break;
    case 0x0C03C610: /* Reflect the third basis vector. */
        for(unsigned i=8;i<12;++i) XF(i)^=0x80000000u; break;
    case 0x0C03CC60: /* Apply affine translation. */
        FR(7)=0x3F800000u; if(!transform(s,4)) return 0;
        FPSCR^=0x100000u; mov(s,13,4); mov(s,15,6); FPSCR^=0x100000u; break;
    case 0x0C03CC90: {
        push(s,ram,R(14)); R(14)=R(4); R(0)=8;
        load(s,ram,6,R(14)+8); R(0)=4; R(3)=0x0C03CC60u;
        load(s,ram,4,R(14)); load(s,ram,5,R(14)+4); R(14)=pop(s,ram);
        return vf3_matrix_family(R(3),s,ram);
    }
    case 0x0C03CCB0: /* Seed the rotational identity while retaining translation. */
        FPSCR^=0x100000u; FR(0)=0; FR(1)=0; FR(2)=0; FR(3)=0x3F800000u;
        mov(s,3,0); mov(s,7,0); mov(s,9,0); mov(s,13,0);
        FR(0)=0x3F800000u; mov(s,1,0); mov(s,11,0); mov(s,5,2); mov(s,15,2);
        FPSCR^=0x100000u; break;
    case 0x0C03C970: /* Rotate using sine/cosine already held in FR4/FR5. */
        mov(s,1,4); FR(4)^=0x80000000u; mov(s,0,5); FR(2)=0; FR(3)=0;
        if(!transform(s,0)) return 0; FR(6)=0; FR(7)=0; if(!transform(s,4)) return 0;
        FPSCR^=0x100000u; mov(s,1,0); mov(s,3,2); mov(s,5,4); mov(s,7,6); FPSCR^=0x100000u; break;
    case 0x0C03C0E0: { /* Multiply an input matrix by XF, preserving caller FR12..15. */
        for(int i=15;i>=13;--i) { R(15)-=width(s); store(s,ram,(unsigned)i,R(15)); }
        FPUL=FR(12);
        for(unsigned base=0;base<16;base+=4) {
            for(unsigned i=base;i<base+4;++i) { load(s,ram,i,R(4)); R(4)+=width(s); }
            if(!transform(s,base)) return 0;
        }
        swap_banks(s); FR(12)=FPUL;
        for(unsigned i=13;i<16;++i) { load(s,ram,i,R(15)); R(15)+=width(s); } break;
    }
    default:
        /* Ownership is selected before execution; failed calls never retry. */
        if(vf3_9970a_adapter_contains(entry)) return vf3_9970a_adapter(entry,s,ram);
        if(vf3_09b_adapter_contains(entry)) return vf3_09b_adapter(entry,s,ram);
        if(vf3_0a67_adapter_contains(entry)) return vf3_0a67_adapter(entry,s,ram);
        if(vf3_03ae_adapter_contains(entry)) return vf3_03ae_adapter(entry,s,ram);
        if(vf3_0c4d_adapter_contains(entry)) return vf3_0c4d_adapter(entry,s,ram);
        if(vf3_0898_adapter_contains(entry)) return vf3_0898_adapter(entry,s,ram);
        if(vf3_c80_adapter_contains(entry)) return vf3_c80_adapter(entry,s,ram);
        if(vf3_c81_adapter_contains(entry)) return vf3_c81_adapter(entry,s,ram);
        if(vf3_c82_adapter_contains(entry)) return vf3_c82_adapter(entry,s,ram);
        if(vf3_c90_adapter_contains(entry)) return vf3_c90_adapter(entry,s,ram);
        if(vf3_advance_closure_adapter_contains(entry)) return vf3_advance_closure_adapter(entry,s,ram);
        if(vf3_advance_worker_adapter_contains(entry)) return vf3_advance_worker_adapter(entry,s,ram);
        if(vf3_advance_leaf_ranked_more_adapter_contains(entry)) return vf3_advance_leaf_ranked_more_adapter(entry,s,ram);
        if(vf3_advance_leaf_ranked_remainder_adapter_contains(entry)) return vf3_advance_leaf_ranked_remainder_adapter(entry,s,ram);
        if(vf3_advance_05b20e_adapter_contains(entry)) return vf3_advance_05b20e_adapter(entry,s,ram);
        if(vf3_tenpp_large_adapter_contains(entry)) return vf3_tenpp_large_adapter(entry,s,ram);
        if(vf3_tenpp_planned_adapter_contains(entry)) return vf3_tenpp_planned_adapter(entry,s,ram);
        if(vf3_tenpp_expanded_adapter_contains(entry)) return vf3_tenpp_expanded_adapter(entry,s,ram);
        if(vf3_tenpp_recovery_adapter_contains(entry)) return vf3_tenpp_recovery_adapter(entry,s,ram);
        if(vf3_tenpp_acceptance_adapter_contains(entry)) return vf3_tenpp_acceptance_adapter(entry,s,ram);
        if(vf3_tenpp_complex_adapter_contains(entry)) return vf3_tenpp_complex_adapter(entry,s,ram);
        if(vf3_tenpp_leaf_adapter_contains(entry)) return vf3_tenpp_leaf_adapter(entry,s,ram);
        if(vf3_phase2_adapter_contains(entry)) return vf3_phase2_adapter(entry,s,ram);
        if(vf3_phase1_adapter_contains(entry)) return vf3_phase1_adapter(entry,s,ram);
        if(vf3_sixth_loader_adapter_contains(entry)) return vf3_sixth_loader_adapter(entry,s,ram);
        if(vf3_seventh_adapter_contains(entry)) return vf3_seventh_adapter(entry,s,ram);
        if(vf3_seventh_c_adapter_contains(entry)) return vf3_seventh_c_adapter(entry,s,ram);
        if(vf3_seventh_c3_adapter_contains(entry)) return vf3_seventh_c3_adapter(entry,s,ram);
        if(vf3_seventh_c4_adapter_contains(entry)) return vf3_seventh_c4_adapter(entry,s,ram);
        if(vf3_seventh_c5_adapter_contains(entry)) return vf3_seventh_c5_adapter(entry,s,ram);
        if(vf3_seventh_c6_adapter_contains(entry)) return vf3_seventh_c6_adapter(entry,s,ram);
        if(vf3_seventh_c7_adapter_contains(entry)) return vf3_seventh_c7_adapter(entry,s,ram);
        if(vf3_seventh_c8_adapter_contains(entry)) return vf3_seventh_c8_adapter(entry,s,ram);
        if(vf3_seventh_c9_adapter_contains(entry)) return vf3_seventh_c9_adapter(entry,s,ram);
        if(vf3_seventh_c10_adapter_contains(entry)) return vf3_seventh_c10_adapter(entry,s,ram);
        if(vf3_seventh_c11_adapter_contains(entry)) return vf3_seventh_c11_adapter(entry,s,ram);
        if(vf3_seventh_c12_adapter_contains(entry)) return vf3_seventh_c12_adapter(entry,s,ram);
        if(vf3_seventh_c13_adapter_contains(entry)) return vf3_seventh_c13_adapter(entry,s,ram);
        if(vf3_seventh_c14_adapter_contains(entry)) return vf3_seventh_c14_adapter(entry,s,ram);
        if(vf3_eighth_adapter_contains(entry)) return vf3_eighth_adapter(entry,s,ram);
        if(vf3_fifth_leaf_adapter_contains(entry)) return vf3_fifth_leaf_adapter(entry,s,ram);
        if(vf3_fifth_adapter_contains(entry)) return vf3_fifth_adapter(entry,s,ram);
        if(vf3_device_adapter_contains(entry)) return vf3_device_adapter(entry,s,ram);
        if(vf3_next_adapter_contains(entry)) return vf3_next_adapter(entry,s,ram);
        if(vf3_motion_adapter_contains(entry)) return vf3_motion_adapter(entry,s,ram);
        if(vf3_fight_adapter_contains(entry)) return vf3_fight_adapter(entry,s,ram);
        if(vf3_motion_final_adapter_contains(entry)) return vf3_motion_final_adapter(entry,s,ram);
        if(vf3_fifth_leaf_unowned_adapter_contains(entry)) return vf3_fifth_leaf_unowned_adapter(entry,s,ram);
        if(vf3_motion_unowned_extra_adapter_contains(entry)) return vf3_motion_unowned_extra_adapter(entry,s,ram);
        if(vf3_fifth_leaf_extra_adapter_contains(entry)) return vf3_fifth_leaf_extra_adapter(entry,s,ram);
        if(vf3_ultimate_adapter_contains(entry)) return vf3_ultimate_adapter(entry,s,ram);
        if(vf3_tenpp_asset_adapter_contains(entry)) return vf3_tenpp_asset_adapter(entry,s,ram);
        if(vf3_tenpp_survey_adapter_contains(entry)) return vf3_tenpp_survey_adapter(entry,s,ram);
        if(vf3_sweep_adapter_contains(entry)) return vf3_sweep_adapter(entry,s,ram);
        if(vf3_aica_stub_adapter_contains(entry)) return vf3_aica_stub_adapter(entry,s,ram);
        if(vf3_tickgap_adapter_contains(entry)) return vf3_tickgap_adapter(entry,s,ram);
        return vf3_matrix_adapter(entry,s,ram);
    }
    s->pc=R(16);
    return ram->oob==0;
}

/* Dispatcher entry. The two verification hooks wrap the generated chain so a
 * readable port can pre-empt any ported entry, and an entry no ported code
 * owns (the chain fails at that very address) can be answered by a recorded
 * oracle effect. Both hooks are NULL outside tests. */
static int vf3_matrix_family_dispatch(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
    int ok, handled=0;
    if(vf3_family_override) {
        ok=vf3_family_override(entry&0x1FFFFFFFu,s,ram,&handled);
        if(handled) return ok;
    }
    ok=vf3_matrix_family_core(entry,s,ram);
    /* A module that reaches a register-indirect jump whose target it was not generated with stops at that target with the jump
     * already taken (delay slot done, pr kept). The target is owned by another module or by nobody: continue there as the tail
     * transfer it is. An exhausted step budget (counter wrapped) is not such a stop and is left to the caller. */
    while(!ok && s->failed_pc) {
        if(s->budget==0xFFFFFFFFu) {   /* the step budget ran out: the hook lets time pass (interrupts) and refills it, in place */
            const uint32_t more=vf3_family_budget_hook?vf3_family_budget_hook():0;
            if(!more) break;
            s->budget=more;
        } else if(!vf3_family_tail_retry || (s->failed_pc&0x1FFFFFFFu)==(entry&0x1FFFFFFFu)) break;
        const uint32_t target=s->failed_pc;
        s->failed_pc=0;
        entry=target;
        ok=vf3_matrix_family_core(entry,s,ram);
    }
    if(!ok && vf3_family_missing && s->failed_pc==(entry&0x1FFFFFFFu)) {
        ok=vf3_family_missing(entry&0x1FFFFFFFu,s,ram,&handled);
        if(handled) return ok;
        ok=0;
    }
    if(!ok && vf3_family_fail) vf3_family_fail(entry&0x1FFFFFFFu,s,ram,&handled);
    return ok;
}
static int vf3_matrix_family_once(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
    int ok;
    if(vf3_family_enter) vf3_family_enter(entry&0x1FFFFFFFu,s,ram,0);
    ok=vf3_matrix_family_dispatch(entry,s,ram);
    if(vf3_family_leave) vf3_family_leave(entry&0x1FFFFFFFu,s,ram,ok);
    return ok;
}
/* A call is finished when control is back at the address the caller put in pr.
 * The generated chain may hand back an earlier pc (a callee that tail-jumped
 * into a fragment, or whose own continuation lives in another adapter); with
 * vf3_family_complete_calls set, the continuation is run here, as a nested
 * dispatch, so its rts is consumed by this call and not by the caller adapter
 * that would otherwise execute the callee's tail inline and then return with
 * the caller's own resume address still pending. */
uint32_t (*vf3_family_budget_hook)(void);
int vf3_family_tail_retry;      /* continue at the target of an indirect jump a module was not generated with */
uint32_t vf3_family_extra_stop;   /* a second address that ends a completion loop (0: none) */
int vf3_family_complete_calls;
int (*vf3_family_call_entry)(uint32_t entry);
int vf3_matrix_family(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
    uint32_t want=s->v[16]&0x1FFFFFFFu;
    int ok=vf3_matrix_family_once(entry,s,ram);
    /* only a real call target owns its pr: a fragment seed entered in the middle of a function sees a
     * stale pr left by an inner call, and must hand its continuation back to the adapter that forwarded it */
    int complete=vf3_family_complete_calls && (!vf3_family_call_entry || vf3_family_call_entry(entry&0x1FFFFFFFu));
    while(complete && ok && (s->pc&0x1FFFFFFFu)!=want && (!vf3_family_extra_stop || (s->pc&0x1FFFFFFFu)!=(vf3_family_extra_stop&0x1FFFFFFFu))) {
        uint32_t next=s->pc;
        if((next&0x1FFFFFFFu)==(entry&0x1FFFFFFFu) && next==entry) break;
        ok=vf3_matrix_family_once(next,s,ram);
        if(ok && s->pc==next) break;
        entry=next;
    }
    return ok;
}
