// Isolated command-line libretro frontend. SPDX-License-Identifier: GPL-2.0-or-later
#include <libretro.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <string>
#include <map>
#include <filesystem>

extern "C" bool vf3_new_reference_done();
static std::string dataDir;
static std::map<std::string,std::string> options;
static bool shutdownRequested;
static unsigned long long pcmFrames;
static void logMessage(enum retro_log_level, const char *format, ...) {
    va_list args; va_start(args,format); std::vfprintf(stderr,format,args); va_end(args);
}
static bool environment(unsigned cmd, void *data) {
    switch(cmd) {
    case RETRO_ENVIRONMENT_GET_LOG_INTERFACE:
        ((retro_log_callback*)data)->log=logMessage; return true;
    case RETRO_ENVIRONMENT_GET_SYSTEM_DIRECTORY:
    case RETRO_ENVIRONMENT_GET_SAVE_DIRECTORY:
        *(const char**)data=dataDir.c_str(); return true;
    case RETRO_ENVIRONMENT_GET_CORE_OPTIONS_VERSION:
        *(unsigned*)data=2; return true;
    case RETRO_ENVIRONMENT_SET_CORE_OPTIONS_V2:
    case RETRO_ENVIRONMENT_SET_CORE_OPTIONS_V2_INTL: {
        auto *defs=cmd==RETRO_ENVIRONMENT_SET_CORE_OPTIONS_V2?
            ((retro_core_options_v2*)data)->definitions:
            ((retro_core_options_v2_intl*)data)->us->definitions;
        for(auto *d=defs;d->key;++d) if(d->default_value) options[d->key]=d->default_value;
        options["reicast_hle_bios"]="enabled";
        options["reicast_threaded_rendering"]="disabled";
        return true;
    }
    case RETRO_ENVIRONMENT_GET_VARIABLE: {
        auto *var=(retro_variable*)data; auto it=options.find(var->key);
        var->value=it==options.end()?nullptr:it->second.c_str(); return var->value!=nullptr;
    }
    case RETRO_ENVIRONMENT_GET_VARIABLE_UPDATE: *(bool*)data=false; return true;
    case RETRO_ENVIRONMENT_GET_LANGUAGE: *(unsigned*)data=RETRO_LANGUAGE_ENGLISH; return true;
    case RETRO_ENVIRONMENT_GET_CAN_DUPE: *(bool*)data=true; return true;
    case RETRO_ENVIRONMENT_GET_AUDIO_VIDEO_ENABLE: *(int*)data=3; return true;
    case RETRO_ENVIRONMENT_GET_FASTFORWARDING: *(bool*)data=false; return true;
    case RETRO_ENVIRONMENT_SHUTDOWN: shutdownRequested=true; return true;
    case RETRO_ENVIRONMENT_SET_PIXEL_FORMAT:
    case RETRO_ENVIRONMENT_SET_INPUT_DESCRIPTORS:
    case RETRO_ENVIRONMENT_SET_SYSTEM_AV_INFO:
    case RETRO_ENVIRONMENT_SET_GEOMETRY:
    case RETRO_ENVIRONMENT_SET_SUPPORT_NO_GAME:
    case RETRO_ENVIRONMENT_SET_CONTROLLER_INFO:
    case RETRO_ENVIRONMENT_SET_CORE_OPTIONS_DISPLAY: return true;
    default: return false;
    }
}
static void video(const void*,unsigned,unsigned,size_t) {}
static void audio(int16_t,int16_t) { ++pcmFrames; }
static size_t audioBatch(const int16_t*,size_t n) { pcmFrames+=n; return n; }
static void poll() {}
static int16_t input(unsigned,unsigned,unsigned,unsigned) { return 0; }
int main(int argc,char **argv) {
    if(argc!=4) { std::fprintf(stderr,"Usage: vf3-reference GAME.gdi PRIVATE_DATA_DIR MAX_FRAMES\n"); return 2; }
    const unsigned frames=std::strtoul(argv[3],nullptr,10);
    if(!frames||frames>20000) return 2;
    dataDir=std::filesystem::absolute(argv[2]).string();
    std::filesystem::create_directories(dataDir+"/dc/data");
    retro_set_environment(environment); retro_set_video_refresh(video);
    retro_set_audio_sample(audio); retro_set_audio_sample_batch(audioBatch);
    retro_set_input_poll(poll); retro_set_input_state(input);
    retro_init();
    retro_game_info game{}; game.path=argv[1];
    if(!retro_load_game(&game)) { std::fprintf(stderr,"[vf3-new] load failed\n"); return 3; }
    unsigned ran=0;
    for(;ran<frames&&!shutdownRequested&&!vf3_new_reference_done();++ran) {
        retro_run();
        if((ran+1)%100==0) std::fprintf(stderr,"[vf3-new] frames=%u pcm_frames=%llu\n",ran+1,pcmFrames);
    }
    std::fprintf(stderr,"[vf3-new] completed frames=%u pcm_frames=%llu capture_stop=%d shutdown=%d\n",ran,pcmFrames,vf3_new_reference_done(),shutdownRequested);
    retro_unload_game(); retro_deinit();
    return shutdownRequested?4:0;
}
