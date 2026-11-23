#ifndef VF3_NATIVE_MATRIX_WRAPPERS_H
#define VF3_NATIVE_MATRIX_WRAPPERS_H
#include "motion_aim.h"
void vf3_native_xform_axis(vf3_native_aim *a);
void vf3_native_store_keep_translation(vf3_native_aim *a);
void vf3_native_rotate_euler(vf3_native_aim *a);
void vf3_native_vec3_load(vf3_native_aim *a);
void vf3_native_call_seq_da1e(vf3_native_aim *a);
void vf3_native_root_orientation_entry(vf3_native_aim *a);
#endif
