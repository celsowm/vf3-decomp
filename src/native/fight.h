#ifndef VF3_NATIVE_FIGHT_H
#define VF3_NATIVE_FIGHT_H

#include <stdint.h>

typedef enum {
    VF3_NATIVE_TITLE = 0,
    VF3_NATIVE_FIGHT,
    VF3_NATIVE_ROUND_END,
    VF3_NATIVE_MATCH_END
} vf3_native_phase;

typedef enum {
    VF3_NATIVE_IDLE = 0,
    VF3_NATIVE_ACTION_PUNCH,
    VF3_NATIVE_ACTION_KICK,
    VF3_NATIVE_ACTION_THROW,
    VF3_NATIVE_HIT,
    VF3_NATIVE_KNOCKOUT
} vf3_native_action;

typedef struct {
    float x;                 /* stage position, 0..1 */
    float depth;             /* 0 is rear, 1 is front */
    int health;
    int rounds;
    int facing;              /* -1 left, +1 right */
    uint8_t fighter_kind;    /* retail actor +0x61 pose-table selector */
    int guarding;
    int action_frame;
    int action_hit;
    vf3_native_action action;
} vf3_native_fighter;

typedef struct {
    vf3_native_phase phase;
    vf3_native_fighter player;
    vf3_native_fighter cpu;
    unsigned round_number;
    unsigned timer_frames;
    unsigned phase_frames;
    unsigned cpu_think_frames;
    unsigned cpu_move;
    unsigned cpu_depth;
    unsigned player_attack;
    unsigned start_down;
    unsigned rematch_down;
    unsigned sound_event;    /* 1 hit, 2 blocked; audio playback pending */
    uint8_t sound_speaker_kind; /* fighter kind that made the last contact */
} vf3_native_fight;

enum {
    VF3_NATIVE_MOVE_LEFT  = 1u << 0,
    VF3_NATIVE_MOVE_RIGHT = 1u << 1,
    VF3_NATIVE_MOVE_BACK  = 1u << 2,
    VF3_NATIVE_MOVE_FWD   = 1u << 3,
    VF3_NATIVE_PUNCH      = 1u << 4,
    VF3_NATIVE_KICK       = 1u << 5,
    VF3_NATIVE_GUARD      = 1u << 6,
    VF3_NATIVE_START      = 1u << 7,
    VF3_NATIVE_REMATCH    = 1u << 8,
    VF3_NATIVE_THROW      = 1u << 9
};

void vf3_native_fight_init(vf3_native_fight *fight);
void vf3_native_fight_step(vf3_native_fight *fight, uint32_t input);

#endif
