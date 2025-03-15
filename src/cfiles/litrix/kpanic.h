void XK_Prefix(Panic)(char *mesg, ERROR_CODE code, BOOL log) {
    clear();
    for(int i = 0; i < 11; i++)
        kputln(0);
    if(log == FALSE) {
        kprintln(mesg);
        kprintln(itoa(code));
    } else {
        klog_println(mesg);
        klog_println(itoa(code));
    }
    asm("hlt");
}
