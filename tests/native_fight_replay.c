/* Deterministic checks for the native match shell and round lifecycle. */
#include "fight.h"

#include <stdio.h>

static int failures;

#define CHECK(condition, message) do { \
    if (!(condition)) { \
        fprintf(stderr, "native_fight_replay: %s\n", message); \
        failures++; \
    } \
} while (0)

static void setup_close_punch(vf3_native_fight *fight, int health)
{
    fight->player.x = 0.40f;
    fight->cpu.x = 0.50f;
    fight->player.depth = 0.50f;
    fight->cpu.depth = 0.50f;
    fight->player.action = VF3_NATIVE_ACTION_PUNCH;
    fight->player.action_frame = 8;
    fight->player.action_hit = 0;
    fight->cpu.action = VF3_NATIVE_IDLE;
    fight->cpu.action_frame = 0;
    fight->cpu.action_hit = 0;
    fight->cpu.guarding = 0;
    fight->cpu.health = health;
}

static void check_start_move_rematch(void)
{
    vf3_native_fight fight;
    vf3_native_fight_init(&fight);
    CHECK(fight.phase == VF3_NATIVE_FIGHT, "match does not start directly");
    CHECK(fight.player.health == 100 && fight.cpu.health == 100,
          "new match health is not full");
    vf3_native_fight_step(&fight, VF3_NATIVE_MOVE_RIGHT);
    CHECK(fight.player.x > 0.30f, "right movement did not advance the player");
    fight.phase = VF3_NATIVE_MATCH_END;
    fight.player.rounds = 2;
    vf3_native_fight_step(&fight, VF3_NATIVE_START);
    CHECK(fight.phase == VF3_NATIVE_FIGHT && fight.player.rounds == 0 &&
          fight.cpu.rounds == 0 && fight.round_number == 1,
          "Enter did not start a direct rematch");
    fight.phase = VF3_NATIVE_MATCH_END;
    vf3_native_fight_step(&fight, VF3_NATIVE_REMATCH);
    CHECK(fight.phase == VF3_NATIVE_FIGHT && fight.player.health == 100,
          "R did not restart the match immediately");
}

static void check_hit_guard_and_match(void)
{
    vf3_native_fight fight;
    vf3_native_fight_init(&fight);
    setup_close_punch(&fight, 100);
    vf3_native_fight_step(&fight, 0);
    CHECK(fight.cpu.health == 90 && fight.player.action_hit,
          "active punch did not hit once");

    vf3_native_fight_init(&fight);
    fight.player.x = 0.40f;
    fight.cpu.x = 0.50f;
    fight.player.depth = fight.cpu.depth = 0.50f;
    fight.cpu.action = VF3_NATIVE_ACTION_KICK;
    fight.cpu.action_frame = 14;
    fight.cpu.action_hit = 0;
    vf3_native_fight_step(&fight, VF3_NATIVE_GUARD);
    CHECK(fight.player.health == 97 && fight.player.action == VF3_NATIVE_IDLE,
          "guard did not reduce an incoming kick");

    vf3_native_fight_init(&fight);
    fight.player.x = 0.45f;
    fight.cpu.x = 0.50f;
    fight.player.depth = fight.cpu.depth = 0.50f;
    fight.cpu.action = VF3_NATIVE_ACTION_THROW;
    fight.cpu.action_frame = 7;
    vf3_native_fight_step(&fight, VF3_NATIVE_GUARD);
    CHECK(fight.player.health == 76 && fight.player.action == VF3_NATIVE_HIT,
          "throw did not beat guard at close range");

    vf3_native_fight_init(&fight);
    setup_close_punch(&fight, 10);
    vf3_native_fight_step(&fight, 0);
    CHECK(fight.phase == VF3_NATIVE_ROUND_END && fight.player.rounds == 1 &&
          fight.cpu.health == 0,
          "knockout did not award the first round");
    fight.phase_frames = 179;
    vf3_native_fight_step(&fight, 0);
    CHECK(fight.phase == VF3_NATIVE_FIGHT && fight.round_number == 2,
          "round transition did not start round two");
    setup_close_punch(&fight, 10);
    vf3_native_fight_step(&fight, 0);
    vf3_native_fight_step(&fight, 0);
    CHECK(fight.phase == VF3_NATIVE_MATCH_END && fight.player.rounds == 2,
          "second knockout did not finish the best-of-three match");
}

static void check_timeout(void)
{
    vf3_native_fight fight;
    vf3_native_fight_init(&fight);
    fight.timer_frames = 1;
    fight.player.health = 45;
    fight.cpu.health = 40;
    vf3_native_fight_step(&fight, 0);
    CHECK(fight.phase == VF3_NATIVE_ROUND_END && fight.player.rounds == 1 &&
          fight.timer_frames == 0,
          "timeout did not award the higher-health fighter");
}

int main(void)
{
    check_start_move_rematch();
    check_hit_guard_and_match();
    check_timeout();
    puts(failures ? "native_fight_replay: FAIL" : "native_fight_replay: PASS");
    return failures ? 1 : 0;
}
