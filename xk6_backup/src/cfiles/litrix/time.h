/* Prints the time and date */
void XK_Prefix(PrintTimeAndDate)() {
    int c = cursor; // push
    cursor = ((63 * 31) + 30) * 2;
    read_rtc();
    kprint(itoa(hour));
    kputc(':');
    kprint(itoa(minute));
    kputc(' ');
    kprint(itoa(day));
    kputc('.');
    kprint(itoa(month));
    kputc('.');
    kprint(itoa(year));
    cursor = c; // pop
}

/* Prints time and date at a location */
void XK_Prefix(PrintTimeAndDateStd)() {
    read_rtc();
    kprint(itoa(hour));
    kputc(':');
    kprint(itoa(minute));
    kputc(' ');
    kprint(itoa(day));
    kputc('.');
    kprint(itoa(month));
    kputc('.');
    kprint(itoa(year));
    kputln(ssize(itoa(year))+ssize(itoa(month))+ssize(itoa(day))+ssize(itoa(hour))+ssize(itoa(minute))+4);
}
