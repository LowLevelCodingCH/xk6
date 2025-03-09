/* Runs on every tick */
void Nx_Prefix(KernelUpdate)(void) {
    for(int i = 0; i < 16; i++) {
        env_user[i] = user[i];
    }

    _glob_color = VGA_COLOR_LIGHT_GREY;

    read_rtc();

    /* Birthday for my mom */
    if(month == 3 && day == 5) {
        int c = cursor;
        cursor = ((80 - 20) * 32) * 2;
        _glob_color = VGA_COLOR_RED;
        kprint("Mama hat geburtstag!!");
        _glob_color = VGA_COLOR_LIGHT_GREY;
        cursor = c;
    }

    XK_ReadXKFS();
    
    kprint(user);
    kputc('/');
    kputc(XKFS.XKFS_DiskLabel);
    kputc(':');
    kputc('>');
    kputc(' ');
    read_word(buffer, 50, ssize(user) + ssize("/_:> "), 0);
    
    cmdsplit(buffer, ' ', cmdbuffer, &cnt);
    
    /* Executes the command */

    XK_SystemExecuteShellCommand(cmdbuffer, cnt);
    
    clearBuffer(buffer, 50);
    for(int i = 0; i < 16; i++) clearBuffer(cmdbuffer[i], 50);
    if(cursor >= 3840) {
        clear();
        reset_cursor();
        cursor = 0;
    }
    
    *(uint32_t*)(0x10000) = cursor;
}

/* Initializes everything that the OS needs */
void Nx_Prefix(KernelInit)(void) {
    read_rtc();

    /* Birthday for my mom */
    if(month == 3 && day == 5) {
        clear();
        for(int i = 0; i < 10; i++)
            kputln(0);

        _glob_color = VGA_COLOR_RED;
        kprint("MAMA ");
        _glob_color = VGA_COLOR_LIGHT_GREEN;
        kprint("HAT GEBURTSTAG!!!!");

        _glob_color = VGA_COLOR_LIGHT_GREY;

        wait_ms(100000);
        clear();
    }

    #ifdef CoolLoadingBar
        for(int i = 0; i < 80; i++) {
            XK_LoadingBarForLookingCool(i);
            wait_ms(CoolLoadingBarDelayFF);
        }
        kprintln("Faster than Arch Linux");
        wait_ms(1100);
        clear();
    #endif

    clear();

    _glob_color = VGA_COLOR_LIGHT_GREY;
    
    klog_println("kernel: Initializing AtA");


    XK_LoadingBarForLookingCool(0);
    wait_ms(CoolLoadingBarDelay);


    init_ata();
    klog_println("kernel: Initializing XKFS");


    XK_LoadingBarForLookingCool(8);
    wait_ms(CoolLoadingBarDelay);
    XK_LoadingBarForLookingCool(16);
    wait_ms(CoolLoadingBarDelay);


    XK_InitXKFS();
    klog_println("kernel: Writing to disk will likely not work!");
    klog_println("kernel: Initializing PiT");


    XK_LoadingBarForLookingCool(24);
    wait_ms(CoolLoadingBarDelay);
    XK_LoadingBarForLookingCool(32);
    wait_ms(CoolLoadingBarDelay);


    init_pit(12);
    klog_println("kernel: Initializing FDs");


    XK_LoadingBarForLookingCool(40);
    wait_ms(CoolLoadingBarDelay);
    XK_LoadingBarForLookingCool(48);
    wait_ms(CoolLoadingBarDelay);


    XK_FileDescriptors[0] = OUTMEM;
    XK_FileDescriptors[1] = TTY_Begin;
    klog_println("kernel: Initializing Users");


    XK_LoadingBarForLookingCool(56);
    wait_ms(CoolLoadingBarDelay);
    XK_LoadingBarForLookingCool(64);
    wait_ms(CoolLoadingBarDelay);


    XK_InitUsers();	
    klog_println("kernel: Initializing IDT");


    XK_LoadingBarForLookingCool(72);
    wait_ms(CoolLoadingBarDelay);
    XK_LoadingBarForLookingCool(80);
    wait_ms(CoolLoadingBarDelay);


    init_idt();

    clear();

    klog_println("kernel: Testing Sound");
    XK_PlayS(startup_beep);
    
    klog_println("kernel: Testing Handles & Memory Allocation");

    HANDLE h = XK_InitHandle();

    XK_AllocatePage(&h, 2);
 
    if(h.pam == 0 || h.adr == NULL) {
        klog_println("kernel: Error with handles");
        asm("hlt");
    }

    XK_FreeHandle(&h);
 
    if(h.pam != 0 || h.adr != NULL) {
        klog_println("kernel: Error with handles");
        asm("hlt");
    }

    klog_println("kernel: Done initializing!");
    XK_Prefix(ListTasks)();
    XK_Prefix(ListUsers)(users, (int)UserAmount);
}
