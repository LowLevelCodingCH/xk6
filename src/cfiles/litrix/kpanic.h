void XK_Prefix(Panic)(BYTE *mesg, ERROR_CODE code, BOOL log) {
    clear();
    for(int i = 0; i < 10; i++)
        kputln(0);
    kprintln("################################Kernel Panicked#################################");
    if(log == FALSE) {
        kprintln(mesg);
        kprintln(itoa(code));
    } else {
        klog_println(mesg);
        klog_println(itoa(code));
    }
    kprintln("################################Kernel End Log##################################");
    asm("hlt");
}
