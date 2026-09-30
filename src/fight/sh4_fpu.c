/* Independent semantic model; no game input/result catalogs. FSCA's fixed
 * coefficient ROM is supplied by the exhaustive, checksummed experiment. */
#include "fight/sh4_fpu.h"
#include <fenv.h>
#include <math.h>
#include <string.h>
#if defined(__SSE__)
#include <xmmintrin.h>
#endif

static const uint32_t sine[32768] = {
#include "sh4_sine.inc"
};
static float as_float(uint32_t u) { float f; memcpy(&f,&u,4); return f; }
static uint32_t as_bits(float f) { uint32_t u; memcpy(&u,&f,4); return u; }
int vf3_fpu_supported(uint32_t fpscr) { return !(fpscr&0x80000u) && (fpscr&3u)<=1; }
void vf3_fpu_fsca(uint32_t angle, uint32_t out[2]) {
    uint32_t a=angle&65535u, b=(a+16384u)&65535u;
    out[0]=sine[a&32767u] ^ ((a&32768u)<<16);
    out[1]=sine[b&32767u] ^ ((b&32768u)<<16);
}
typedef struct { fenv_t env;
#if defined(__SSE__)
    unsigned csr;
#endif
} HostEnv;
static void begin(HostEnv *e,uint32_t fpscr) {
    fegetenv(&e->env);
#if defined(__SSE__)
    e->csr=_mm_getcsr();
#endif
    fesetround((fpscr&1u)?FE_TOWARDZERO:FE_TONEAREST);
#if defined(__SSE__)
    /* The interpreter enables FTZ but leaves DAZ clear on this host. */
    _mm_setcsr((_mm_getcsr()&~0x8040u)|((fpscr&0x40000u)?0x8000u:0));
#endif
}
static void end(HostEnv *e) {
    fesetenv(&e->env);
#if defined(__SSE__)
    _mm_setcsr(e->csr);
#endif
}
static float flush(float f,uint32_t fpscr) {
    uint32_t u=as_bits(f);
    if((fpscr&0x40000u) && !(u&0x7F800000u) && (u&0x7FFFFFu)) u&=0x80000000u;
    return as_float(u);
}
uint32_t vf3_fpu_binary(uint32_t a,uint32_t b,uint32_t fpscr,char operation) {
    HostEnv e; volatile float x=as_float(a),y=as_float(b),z=0;
    begin(&e,fpscr);
    switch(operation) { case '+': z=x+y; break; case '-': z=x-y; break; case '*': z=x*y; break; case '/': z=x/y; break; }
    uint32_t result=as_bits(flush(z,fpscr)); end(&e); return result;
}
uint32_t vf3_fpu_sqrt(uint32_t a,uint32_t fpscr) {
    HostEnv e; begin(&e,fpscr); volatile float z=sqrtf(as_float(a));
    uint32_t result=as_bits(flush(z,fpscr)); end(&e); return result;
}
uint32_t vf3_fpu_float(uint32_t value,uint32_t fpscr) {
    HostEnv e; begin(&e,fpscr); volatile int32_t input=(int32_t)value;
    volatile float converted=(float)input;
    uint32_t result=as_bits(converted); end(&e); return result;
}
uint32_t vf3_fpu_ftrc(uint32_t value) {
    double d=as_float(value);
    if(isnan(d) || d< -2147483648.0) return 0x80000000u;
    if(d>=2147483648.0) return 0x7fffffffu;
    return (uint32_t)(int32_t)d;
}
uint32_t vf3_fpu_mac(uint32_t a,uint32_t b,uint32_t c,uint32_t fpscr) {
    HostEnv e; begin(&e,fpscr); volatile float z=fmaf(as_float(a),as_float(b),as_float(c));
    uint32_t result=as_bits(flush(z,fpscr)); end(&e); return result;
}
int vf3_fpu_fsrra(uint32_t value,uint32_t fpscr,uint32_t *result) {
    HostEnv e;
    if(!vf3_fpu_supported(fpscr)) return 0;
    begin(&e,fpscr);
    volatile float root=sqrtf(as_float(value));
    volatile float inverse=1.0f/root;
    *result=as_bits(flush(inverse,fpscr));
    end(&e); return 1;
}
static float dot(const uint32_t a[4],const uint32_t b[4]) {
    volatile double sum=(double)as_float(a[0])*(double)as_float(b[0]);
    for(unsigned i=1;i<4;++i) {
        volatile double product=(double)as_float(a[i])*(double)as_float(b[i]);
        /* Preserve the accumulated NaN's sign/payload. Host compilers may
         * exchange ADD operands even with contraction disabled. */
        if (!isnan(sum)) sum=sum+product;
    }
    return (float)sum;
}
int vf3_fpu_fipr(const uint32_t a[4],const uint32_t b[4],uint32_t fpscr,uint32_t *result) {
    HostEnv e;
    if(!vf3_fpu_supported(fpscr)) return 0;
    begin(&e,fpscr); *result=as_bits(flush(dot(a,b),fpscr)); end(&e); return 1;
}
int vf3_fpu_ftrv(const uint32_t matrix[16],const uint32_t vector[4],uint32_t fpscr,uint32_t result[4]) {
    HostEnv e; uint32_t source[4];
    if(!vf3_fpu_supported(fpscr)) return 0;
    memcpy(source,vector,sizeof(source));
    begin(&e,fpscr);
    for(unsigned i=0;i<4;++i) {
        uint32_t row[4]={matrix[i],matrix[i+4],matrix[i+8],matrix[i+12]};
        result[i]=as_bits(flush(dot(row,source),fpscr));
    }
    end(&e); return 1;
}
