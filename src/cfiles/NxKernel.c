#include <errorprev.h>
#include <settings.h>
#include <xkstd.h>
#include <systemx.h>
#include <libc.h>

void Nx_Kernel(void) {
    clear();

    klog_println("kernel: Initializing Scheduler & Multitasking");
    klog_println("kernel: Initializing SystemX");

    XK_InitializeScheduler(&SystemX);

    clear();
    XK_TryLogin(&logged_in, 1);

    while (1 == XK_IsRunning(0)) {
        XK_SystemTick();
        XK_StepTasks();
    }

    XK_Panic("kernel: Kernel stopped", FAULT_UNKNOWN, FALSE);
}
