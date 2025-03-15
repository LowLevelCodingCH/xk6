#ifndef STDIO_H
#define STDIO_H

/* Standard values, variables and types */

#include <nitrix/std.h>
#include <nitrix/task.h>

/* Drivers (ugly code) */

#include <jitrix/mario.h>
#include <jitrix/textkb.h>
#include <jitrix/pit_sound.h>
#include <jitrix/diskio.h>
#include <jitrix/cmos.h>

/* My libraries for xk*/

#include <litrix/kpanic.h>
#include <litrix/mem.h>
#include <litrix/time.h>
#include <litrix/misc.h>
#include <litrix/xkfs.h>
#include <litrix/users.h>
#include <litrix/executable.h>
#include <litrix/syscalls.h>
#include <litrix/scheduler.h>
#include <litrix/loadingbar.h>
#include <litrix/shell.h>

/* Default important */

#include <nitrix/idt.h>
#include <nitrix/kerneltask.h>

#endif
