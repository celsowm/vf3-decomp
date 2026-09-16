/* VF3tb source-port bootstrap (clean-room reconstruction).
 *
 * Long-term goal: host-native build of the reconstructed VF3tb game logic.
 * Everything here is written from our own reverse-engineering notes;
 * no Sega/NEC library code is used.
 */
#include <stdio.h>
#include "sys/hal.h"

static void vf3_init(void)
{
    hal_log("vf3: init\n");
}

static int vf3_frame(void)
{
    /* placeholder game loop tick; returns 0 to quit */
    return 0;
}

int main(void)
{
    vf3_init();
    while (vf3_frame())
        ;
    hal_log("vf3: shutdown\n");
    return 0;
}
