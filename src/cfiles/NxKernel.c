#include <errorprev.h>
#include <settings.h>
#include <xkstd.h>
#include <systemx.h>

void Nx_Kernel(void) {
    if(XK_IsComputerOn() != 1) {
        kprintln("misc: Computer is not turned on, please turn it on");
        asm("hlt");
    }
    if(XK_IsComputerOnFire() == 1) {
        kprintln("misc: Computer is on fire, please use sand, not water");
        asm("hlt");
    }

    klog_println("kernel: Initializing Scheduler & Multitasking");
    klog_println("kernel: Initializing SystemX");
    XK_InitializeScheduler(&SystemX);

    #ifdef __Kernel_Print_Log_Then_Halt__ 
        asm("hlt");
    #endif

    clear();

    XK_PrintTimeAndDate();
    XK_TryLogin(&logged_in, 1);

    while (1 == XK_IsRunning(0)) {
        XK_SystemTick();
        XK_StepTasks();
    }

    klog_println("kernel: Kernel stopped. Shut down.");

    asm("hlt");
}
