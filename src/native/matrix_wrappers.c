/* Native wrappers around the point transform and matrix store. */
#include "matrix_wrappers.h"
#include "aim_math.h"
#include "matrix_io.h"
#include "xform_point.h"
#include "matrix_rotate_x.h"
#include "matrix_rotate_y.h"
#include "matrix_rotate_z.h"
#include "matrix_translate_by.h"
#include "matrix_set_translation.h"
#include "xmtrx_identity.h"
#include "xf_store.h"

void vf3_native_xform_axis(vf3_native_aim *a)
{
    uint32_t sp=a->r[15],pr=a->pr,dest=a->r[4],f=sp-20;
    vf3_aim_set_u32(a,sp-4,pr);vf3_aim_set_u32(a,f,dest);
    vf3_aim_set_u32(a,f+4,vf3_aim_ubits(a->fr[4]));a->fr[4]=0;
    vf3_aim_set_u32(a,f+8,0);vf3_aim_set_u32(a,f+12,0);
    a->r[0]=12;a->r[3]=0x0c03b450u;a->r[4]=f+4;a->r[5]=dest;a->r[15]=f;
    a->pr=0x0c09d54cu;vf3_native_xform_point(a);a->r[15]=sp;a->pr=pr;
}

void vf3_native_store_keep_translation(vf3_native_aim *a)
{
    uint32_t sp=a->r[15],pr=a->pr,r14=a->r[14],r13=a->r[13],object=a->r[4],f=sp-24;
    vf3_aim_set_u32(a,sp-4,r14);vf3_aim_set_u32(a,sp-8,r13);vf3_aim_set_u32(a,sp-12,pr);
    for(int i=0;i<3;++i){a->fr[3]=vf3_aim_fbits(vf3_aim_u32(a,object+48+4*i));vf3_aim_set_u32(a,f+4*i,vf3_aim_ubits(a->fr[3]));}
    a->r[0]=56;a->r[14]=object;a->r[13]=f;a->r[15]=f;a->r[3]=0x0c03b620u;
    a->pr=0x0c09d50eu;vf3_native_matrix_store(a);
    for(int i=0;i<3;++i){a->fr[3]=vf3_aim_fbits(vf3_aim_u32(a,f+4*i));vf3_aim_set_u32(a,object+48+4*i,vf3_aim_ubits(a->fr[3]));}
    a->r[0]=56;a->r[15]=sp;a->r[14]=r14;a->r[13]=r13;a->pr=pr;
}

void vf3_native_rotate_euler(vf3_native_aim *a)
{
    uint32_t sp=a->r[15],pr=a->pr,angles=a->r[4],f=sp-16;
    uint32_t z=vf3_aim_h16(a,angles),y=vf3_aim_h16(a,angles+2),x=vf3_aim_h16(a,angles+4);
    vf3_aim_set_u32(a,sp-4,pr);vf3_aim_set_u16(a,f+8,(uint16_t)z);
    vf3_aim_set_u16(a,f+4,(uint16_t)y);vf3_aim_set_u16(a,f,(uint16_t)x);a->r[15]=f;
    a->r[0]=(uint32_t)(int32_t)(int16_t)z;a->r[3]=0x0c03c940u;a->r[4]=z;a->pr=0x0c09d49au;
    vf3_native_matrix_rotate_z(a);
    a->r[0]=(uint32_t)(int32_t)(int16_t)y;a->r[3]=0x0c03c880u;a->r[4]=y;a->r[15]=f;a->pr=0x0c09d4a4u;
    vf3_native_matrix_rotate_y(a);
    a->r[4]=x;a->r[15]=sp;a->r[3]=0x0c03c6c0u;a->pr=pr;
    vf3_native_matrix_rotate_x(a);
}

void vf3_native_vec3_load(vf3_native_aim *a)
{
    uint32_t p=a->r[4];vf3_aim_set_u32(a,a->r[15]-4,a->r[14]);
    a->fr[6]=vf3_aim_fbits(vf3_aim_u32(a,p+8));
    a->fr[4]=vf3_aim_fbits(vf3_aim_u32(a,p));
    a->fr[5]=vf3_aim_fbits(vf3_aim_u32(a,p+4));
    a->r[0]=4;a->r[3]=0x0c03cc60u;
    vf3_native_matrix_translate_by(a);
}

void vf3_native_call_seq_da1e(vf3_native_aim *a)
{
    uint32_t sp=a->r[15],pr=a->pr,f=sp-24,saved=a->r[14],in=a->r[4],owner=a->r[5];
    vf3_aim_set_u32(a,sp-4,saved);vf3_aim_set_u32(a,sp-8,pr);
    a->r[14]=in;a->r[15]=f;a->r[4]=f;vf3_aim_set_u32(a,f,owner);
    a->r[4]=f+4;a->r[3]=0x0c03b820u;a->pr=0x0c09da30u;vf3_native_xf_store(a);
    a->r[2]=0x0c03ccb0u;a->pr=0x0c09da36u;vf3_native_xmtrx_identity(a);
    a->r[4]=vf3_aim_u32(a,f);a->r[3]=0x0c03c880u;
    a->r[0]=(uint32_t)(int32_t)(int16_t)vf3_aim_h16(a,a->r[4]+30);a->r[4]=a->r[0];
    a->pr=0x0c09da40u;vf3_native_matrix_rotate_y(a);
    a->r[2]=0x0c03c940u;a->r[4]=vf3_aim_h16(a,in);a->pr=0x0c09da48u;vf3_native_matrix_rotate_z(a);
    a->r[3]=0x0c03c880u;a->r[0]=(uint32_t)(int32_t)(int16_t)vf3_aim_h16(a,in+2);a->r[4]=a->r[0]&0xffffu;
    a->pr=0x0c09da50u;vf3_native_matrix_rotate_y(a);
    a->r[4]=vf3_aim_u32(a,f);a->r[2]=0x22e6u;a->r[0]=(uint32_t)(int32_t)(int16_t)vf3_aim_h16(a,in+4);
    a->r[2]+=a->r[4];a->r[3]=0x0c03c6c0u;a->r[4]=(uint32_t)(int32_t)(int16_t)vf3_aim_h16(a,a->r[2]);
    a->r[0]&=0xffffu;a->r[4]+=a->r[0];a->pr=0x0c09da64u;vf3_native_matrix_rotate_x(a);
    a->r[2]=0x0c03cbd0u;a->r[4]=f+4;a->pr=0x0c09da6au;vf3_native_matrix_set_translation(a);
    a->r[15]=sp;a->pr=pr;a->r[14]=saved;
}

void vf3_native_root_orientation_entry(vf3_native_aim *a)
{
    uint32_t sp=a->r[15],pr=a->pr,saved=a->r[14],obj=a->r[4];
    vf3_aim_set_u32(a,sp-4,saved);vf3_aim_set_u32(a,sp-8,pr);a->r[15]=sp-8;a->r[14]=obj;
    a->pr=0x0c09d9f4u;vf3_native_xmtrx_identity(a);
    a->r[4]=(uint32_t)(int32_t)(int16_t)vf3_aim_h16(a,obj+30);a->pr=0x0c09d9fcu;vf3_native_matrix_rotate_y(a);
    a->r[0]=(uint32_t)(int32_t)(int16_t)vf3_aim_h16(a,0x0c09daccu);
    a->r[4]=vf3_aim_h16(a,obj+a->r[0]);a->pr=0x0c09da06u;vf3_native_matrix_rotate_z(a);
    a->r[0]=(uint32_t)(int32_t)(int16_t)vf3_aim_h16(a,0x0c09daceu);
    a->r[4]=vf3_aim_h16(a,obj+a->r[0]);a->pr=0x0c09da10u;vf3_native_matrix_rotate_y(a);
    a->r[0]=(uint32_t)(int32_t)(int16_t)vf3_aim_h16(a,0x0c09dad0u);a->pr=pr;
    a->r[4]=vf3_aim_h16(a,obj+a->r[0]);a->r[3]=vf3_aim_u32(a,0x0c09dae4u);
    a->r[14]=saved;a->r[15]=sp;vf3_native_matrix_rotate_x(a);
}
