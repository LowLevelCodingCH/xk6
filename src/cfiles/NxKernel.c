#include <errorprev.h>
#include <settings.h>
#include <xkstd.h>

Task SystemX = {
    .running = TASK_RUNNING_FLAG,        // Runs    (If it runs or not)
    .length  = TASK_FOREVER_FLAG,        // Forever (-1: Forever. Everything else is the length of the task in ticks)
    .current_tick = 0,                   // Tick    (What SystemTick it is right now, to know when to exit)
    .name = "SystemX",                   // Name    (Name)
    .hasupdate = 1,                      // Unused  (Was meant to tell if it has an update function)
    .update = &Nx_KernelUpdate,          // Update  (Called every tick)     (cfiles/nitrix/kerneltask.h)
    .init = &Nx_KernelInit,              // Init    (Called once)           (cfiles/nitrix/kerneltask.h)
    .exists = TASK_EXIST_FLAG            // Exists  (TASK_EXIST_FLAG = 121. To prevent from NULL from being executed. If this isn't here, bugs are hard to find, it happened, trust me)
};

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

    klog_println("kernel: Kernel stopped.");

    asm("hlt");
}
