/* Native match-state blockout.
 *
 * This module owns the match state in ordinary C and has no guest memory,
 * SH-4 state, generated adapters, emulator callbacks, or device bus. The
 * timing, reach, damage, and CPU choices below are scaffolding, not recovered
 * VF3 values. Replace them from the readable decomp before calling the port
 * playable. */
#include "fight.h"

#include <string.h>

#define ROUND_FRAMES       (99u * 60u)
#define ROUND_END_FRAMES   180u
#define WALK_SPEED         0.0052f
#define DEPTH_SPEED        0.0037f
#define PUNCH_ACTIVE_FIRST 8
#define PUNCH_ACTIVE_LAST  11
#define PUNCH_RECOVERY     23
#define KICK_ACTIVE_FIRST  14
#define KICK_ACTIVE_LAST   18
#define KICK_RECOVERY      33
#define THROW_ACTIVE_FIRST 7
#define THROW_ACTIVE_LAST  9
#define THROW_RECOVERY     38
#define THROW_DAMAGE       24
#define HIT_STUN_FRAMES    20

static float clampf(float value, float low, float high)
{
    if (value < low) return low;
    if (value > high) return high;
    return value;
}

static int attack_active(vf3_native_action action, int frame)
{
    if (action == VF3_NATIVE_ACTION_PUNCH)
        return frame >= PUNCH_ACTIVE_FIRST && frame <= PUNCH_ACTIVE_LAST;
    if (action == VF3_NATIVE_ACTION_KICK)
        return frame >= KICK_ACTIVE_FIRST && frame <= KICK_ACTIVE_LAST;
    if (action == VF3_NATIVE_ACTION_THROW)
        return frame >= THROW_ACTIVE_FIRST && frame <= THROW_ACTIVE_LAST;
    return 0;
}

static int attack_recovery(vf3_native_action action)
{
    if (action == VF3_NATIVE_ACTION_PUNCH) return PUNCH_RECOVERY;
    if (action == VF3_NATIVE_ACTION_KICK) return KICK_RECOVERY;
    if (action == VF3_NATIVE_ACTION_THROW) return THROW_RECOVERY;
    return 0;
}

static int can_act(const vf3_native_fighter *fighter)
{
    return fighter->action == VF3_NATIVE_IDLE;
}

static void start_attack(vf3_native_fighter *fighter, vf3_native_action action)
{
    if (!can_act(fighter)) return;
    fighter->action = action;
    fighter->action_frame = 0;
    fighter->action_hit = 0;
    fighter->guarding = 0;
}

static void update_facing(vf3_native_fight *fight)
{
    if (fight->cpu.x < fight->player.x) {
        fight->player.facing = -1;
        fight->cpu.facing = 1;
    } else {
        fight->player.facing = 1;
        fight->cpu.facing = -1;
    }
}

static void move_fighter(vf3_native_fighter *fighter, int direction,
                         int depth_direction)
{
    if (!can_act(fighter)) return;
    fighter->x = clampf(fighter->x + (float)direction * WALK_SPEED,
                        0.09f, 0.91f);
    fighter->depth = clampf(fighter->depth + (float)depth_direction * DEPTH_SPEED,
                            0.16f, 0.84f);
}

static void resolve_hit(vf3_native_fight *fight,
                        vf3_native_fighter *attacker,
                        vf3_native_fighter *defender,
                        int is_player)
{
    if (!attack_active(attacker->action, attacker->action_frame) ||
        attacker->action_hit)
        return;

    const float horizontal = defender->x - attacker->x;
    const float distance = horizontal * (float)attacker->facing;
    const float lane = defender->depth - attacker->depth;
    const int kick = attacker->action == VF3_NATIVE_ACTION_KICK;
    const int is_throw = attacker->action == VF3_NATIVE_ACTION_THROW;
    const float reach = is_throw ? 0.095f : kick ? 0.19f : 0.135f;
    const float lane_reach = kick ? 0.22f : 0.17f;
    if (distance < 0.0f || distance > reach || lane < -lane_reach || lane > lane_reach)
        return;

    attacker->action_hit = 1;
    const int blocked = !is_throw && defender->guarding &&
                        defender->action == VF3_NATIVE_IDLE &&
                        defender->facing == -attacker->facing;
    const int damage = is_throw ? THROW_DAMAGE : kick ? 17 : 10;
    defender->health -= blocked ? (damage + 5) / 6 : damage;
    if (defender->health < 0) defender->health = 0;
    if (!blocked) {
        defender->action = defender->health ? VF3_NATIVE_HIT : VF3_NATIVE_KNOCKOUT;
        defender->action_frame = 0;
        defender->guarding = 0;
    }
    fight->sound_event = blocked ? 2u : 1u;
    if (!defender->health) {
        fight->phase = VF3_NATIVE_ROUND_END;
        fight->phase_frames = 0;
        if (is_player) ++fight->player.rounds;
        else ++fight->cpu.rounds;
    }
}

static void advance_action(vf3_native_fighter *fighter)
{
    if (fighter->action == VF3_NATIVE_ACTION_PUNCH ||
        fighter->action == VF3_NATIVE_ACTION_KICK ||
        fighter->action == VF3_NATIVE_ACTION_THROW) {
        ++fighter->action_frame;
        if (fighter->action_frame >= attack_recovery(fighter->action)) {
            fighter->action = VF3_NATIVE_IDLE;
            fighter->action_frame = 0;
            fighter->action_hit = 0;
        }
    } else if (fighter->action == VF3_NATIVE_HIT) {
        if (++fighter->action_frame >= HIT_STUN_FRAMES) {
            fighter->action = VF3_NATIVE_IDLE;
            fighter->action_frame = 0;
        }
    }
}

static void reset_round(vf3_native_fight *fight)
{
    fight->player.x = 0.30f;
    fight->player.depth = 0.58f;
    fight->player.health = 100;
    fight->player.facing = 1;
    fight->player.fighter_kind = 0;
    fight->player.action = VF3_NATIVE_IDLE;
    fight->player.action_frame = 0;
    fight->player.action_hit = 0;
    fight->player.guarding = 0;
    fight->cpu.x = 0.70f;
    fight->cpu.depth = 0.42f;
    fight->cpu.health = 100;
    fight->cpu.facing = -1;
    fight->cpu.fighter_kind = 7;
    fight->cpu.action = VF3_NATIVE_IDLE;
    fight->cpu.action_frame = 0;
    fight->cpu.action_hit = 0;
    fight->cpu.guarding = 0;
    fight->timer_frames = ROUND_FRAMES;
    fight->phase_frames = 0;
    fight->cpu_think_frames = 0;
    fight->cpu_move = 0;
    fight->cpu_depth = 0;
    fight->player_attack = 0;
    fight->sound_event = 0;
    update_facing(fight);
}

static void begin_match(vf3_native_fight *fight)
{
    fight->round_number = 1;
    fight->player.rounds = 0;
    fight->cpu.rounds = 0;
    reset_round(fight);
    fight->phase = VF3_NATIVE_FIGHT;
}

void vf3_native_fight_init(vf3_native_fight *fight)
{
    memset(fight, 0, sizeof *fight);
    begin_match(fight);
}

static void step_cpu(vf3_native_fight *fight)
{
    vf3_native_fighter *cpu = &fight->cpu;
    const vf3_native_fighter *player = &fight->player;
    const float horizontal = player->x - cpu->x;
    const float distance = horizontal < 0.0f ? -horizontal : horizontal;
    const float lane = player->depth - cpu->depth;

    cpu->guarding = 0;
    if (player->action == VF3_NATIVE_ACTION_PUNCH ||
        player->action == VF3_NATIVE_ACTION_KICK ||
        player->action == VF3_NATIVE_ACTION_THROW) {
        const int warning = player->action_frame >= 3 && player->action_frame <
            (player->action == VF3_NATIVE_ACTION_PUNCH ? PUNCH_ACTIVE_FIRST :
             player->action == VF3_NATIVE_ACTION_KICK ? KICK_ACTIVE_FIRST :
             THROW_ACTIVE_FIRST);
        if (warning && distance < 0.20f && lane > -0.23f && lane < 0.23f &&
            ((fight->phase_frames / 7u) % 3u) != 0u)
            cpu->guarding = 1;
    }
    if (!can_act(cpu)) return;
    if (cpu->guarding) return;

    if (fight->cpu_think_frames) {
        --fight->cpu_think_frames;
        move_fighter(cpu, (int)fight->cpu_move - 1, (int)fight->cpu_depth - 1);
        return;
    }

    ++fight->phase_frames;
    fight->cpu_think_frames = 3u + (fight->phase_frames % 5u);
    if (distance > 0.155f) {
        fight->cpu_move = horizontal < 0.0f ? 0u : 2u;
        fight->cpu_depth = lane < 0.0f ? 0u : 2u;
        move_fighter(cpu, (int)fight->cpu_move - 1, (int)fight->cpu_depth - 1);
    } else if (distance < 0.075f && (fight->phase_frames % 4u) == 0u) {
        fight->cpu_move = horizontal < 0.0f ? 2u : 0u;
        fight->cpu_depth = 1u;
        move_fighter(cpu, (int)fight->cpu_move - 1, 0);
    } else if ((fight->phase_frames % 3u) != 0u) {
        const vf3_native_action action = (fight->phase_frames % 11u) == 0u
            ? VF3_NATIVE_ACTION_THROW
            : (fight->phase_frames % 5u) == 0u
                ? VF3_NATIVE_ACTION_KICK : VF3_NATIVE_ACTION_PUNCH;
        start_attack(cpu, action);
    }
}

static void step_round_end(vf3_native_fight *fight, uint32_t input)
{
    ++fight->phase_frames;
    if (fight->player.rounds >= 2 || fight->cpu.rounds >= 2) {
        fight->phase = VF3_NATIVE_MATCH_END;
        fight->phase_frames = 0;
    } else if (fight->phase_frames >= ROUND_END_FRAMES || (input & VF3_NATIVE_START)) {
        ++fight->round_number;
        reset_round(fight);
        fight->phase = VF3_NATIVE_FIGHT;
    }
}

void vf3_native_fight_step(vf3_native_fight *fight, uint32_t input)
{
    fight->sound_event = 0;
    const int start_pressed = (input & VF3_NATIVE_START) && !fight->start_down;
    const int rematch_pressed = (input & VF3_NATIVE_REMATCH) && !fight->rematch_down;
    fight->start_down = !!(input & VF3_NATIVE_START);
    fight->rematch_down = !!(input & VF3_NATIVE_REMATCH);

    if (rematch_pressed) {
        begin_match(fight);
        return;
    }

    if (fight->phase == VF3_NATIVE_TITLE) {
        if (start_pressed) begin_match(fight);
        return;
    }
    if (fight->phase == VF3_NATIVE_MATCH_END) {
        if (start_pressed) begin_match(fight);
        return;
    }
    if (fight->phase == VF3_NATIVE_ROUND_END) {
        step_round_end(fight, start_pressed ? VF3_NATIVE_START : 0u);
        return;
    }

    if (fight->timer_frames) --fight->timer_frames;
    const int horizontal = !!(input & VF3_NATIVE_MOVE_RIGHT) - !!(input & VF3_NATIVE_MOVE_LEFT);
    const int depth = !!(input & VF3_NATIVE_MOVE_FWD) - !!(input & VF3_NATIVE_MOVE_BACK);
    /* The horizontal controls are relative to the opponent: pressing toward
     * the opponent keeps advancing after the fighters cross and exchange
     * facing. `horizontal` is the screen-space input; convert it to stage X
     * before applying the shared world-space movement helper. */
    move_fighter(&fight->player, horizontal * fight->player.facing, depth);
    fight->player.guarding = !!(input & VF3_NATIVE_GUARD) && can_act(&fight->player);

    if (!fight->player_attack) {
        const uint32_t throw_buttons = VF3_NATIVE_PUNCH | VF3_NATIVE_GUARD;
        /* VF3's standard throw is Punch + Guard. The low throw adds Kick.
         * Both combinations feed the current blockout throw action; V/RB is
         * retained as a convenient one-button shortcut for the native slice. */
        if ((input & throw_buttons) == throw_buttons ||
            (input & VF3_NATIVE_THROW))
            start_attack(&fight->player, VF3_NATIVE_ACTION_THROW);
        else if (input & VF3_NATIVE_KICK)
            start_attack(&fight->player, VF3_NATIVE_ACTION_KICK);
        else if (input & VF3_NATIVE_PUNCH)
            start_attack(&fight->player, VF3_NATIVE_ACTION_PUNCH);
    }
    fight->player_attack = input &
        (VF3_NATIVE_PUNCH | VF3_NATIVE_KICK | VF3_NATIVE_THROW);

    step_cpu(fight);
    update_facing(fight);
    resolve_hit(fight, &fight->player, &fight->cpu, 1);
    if (fight->phase == VF3_NATIVE_FIGHT)
        resolve_hit(fight, &fight->cpu, &fight->player, 0);
    advance_action(&fight->player);
    advance_action(&fight->cpu);

    if (fight->phase == VF3_NATIVE_FIGHT && !fight->timer_frames) {
        if (fight->player.health >= fight->cpu.health) ++fight->player.rounds;
        else ++fight->cpu.rounds;
        fight->phase = VF3_NATIVE_ROUND_END;
        fight->phase_frames = 0;
    }
}
