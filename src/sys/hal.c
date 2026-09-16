#include "hal.h"
#include <stdio.h>

void hal_log(const char *msg)
{
    fputs(msg, stdout);
}
