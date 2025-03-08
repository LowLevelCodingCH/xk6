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
