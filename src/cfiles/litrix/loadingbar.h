void XK_Prefix(LoadingBarForLookingCool)(int stat) {
    _glob_color = VGA_COLOR_LIGHT_GREY;
    clear();
    for(int i = 0; i < 10; i++)
        kputln(0);
    _glob_color = (VGA_COLOR_LIGHT_CYAN << 8) | '0';
    kprintln("-----------------------------XKOS Initializing----------------------------------");
    _glob_color = VGA_COLOR_WHITE;
    _glob_color = (VGA_COLOR_WHITE << 8) | '1';
    for(int i = 0; i < stat; i++)
        kputc('X');
    for(int i = 0; i < 80 - stat; i++)
        kputc('-');
    _glob_color = (VGA_COLOR_LIGHT_CYAN << 8) | '0';
    kprintln("--------------------------------------------------------------------------------");
    _glob_color = VGA_COLOR_LIGHT_GREY;
}

