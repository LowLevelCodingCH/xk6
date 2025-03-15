/* Defines a couple commands that the SystemExecuteCommand can use */
void echo(char command[16][50], int count) {
    int major = 0;
    for(int i = 1; i < cnt; i++) {
        printf("%s ", command[i]);
        major += ssize(command[i]) + 1;
    }
    kputln(major);
}

void ls(char command[16][50], int count) {
    XK_ReadXKFS();
    XK_ListFiles(FST_Entries);
}

void ps(char command[16][50], int count) {
    XK_ListTasks();
}

void call(char command[16][50], int count) {
    XK_CallAddress(atoi(command[1]));
}

void kill(char command[16][50], int count) {
    XK_RemoveTask(atoi(command[1]));
}

void killall(void) {
    XK_RemoveAllTasks();
}

void cat(char command[16][50], int count) {
    XK_ReadXKFS();
    int idx = XK_GetFileIndex(FST_Entries, FST.files_amount, command[1]);
    if(idx != -1)
        XK_ReadFileByIndexPrint(FST_Entries, FST_Blocks, idx);
    else kprintln("[io::xkfs] No such file");
}

void rfd(char command[16][50], int count) {
    XK_ReadXKFS();
    int idx = XK_GetFileIndex(FST_Entries, FST.files_amount, command[1]);
    if(idx != -1)
        XK_ReadFileData(FST_Entries, FST_Blocks, idx);
    else kprintln("[io::xkfs] No such file");
}

void cbeep(char command[16][50], int count) {
    beep(atoi(command[1]),atoi(command[2]));
}

void rdram(char command[16][50], int count) {
    kprintbuf((char*)atoi(command[1]), atoi(command[2]));
}

void lsusrs(void) {
    XK_ListUsers(users, (int)UserAmount);
}

void printenv(void) {
    kprint("$user = ");
    kprint(env_user);
    kputln(ssize("$user = ") + ssize(env_user));
    kprint("$root = ");
    kprint(env_root);
    kputln(ssize("$root = ") + ssize(env_root));
    kprint("$home = ");
    kprint(env_home);
    kputln(ssize("$home = ") + ssize(env_home));
}

void timedatectl(void) {
    XK_PrintTimeAndDateStd();
}

void exit(void) {
    XK_RemoveTask(0);
}

/* Executes a shell command with a count and command */
void XK_Prefix(SystemExecuteShellCommand(char command[16][50], int count)) {
    if(streq(command[0],"echo")==0)            echo(command, count);
    if(count == 1) {
        if(streq(command[0],"exit")==0)        exit();
        if(streq(command[0],"clear")==0)       clear();
        if(streq(command[0],"ps")==0)          ps(command, count);
        if(streq(command[0],"ls")==0)          ls(command, count);
        if(streq(command[0],"printenv")==0)    printenv();
        if(streq(command[0],"killall")==0)     killall();
        if(streq(command[0],"timedatectl")==0) timedatectl();
        if(streq(command[0],"lsusrs")==0)      lsusrs();
    }
    if(count == 2) {
        if(streq(command[0],"call")==0)        call(command, count);
        if(streq(command[0],"kill")==0)        kill(command, count);
        if(streq(command[0],"cat")==0)         cat(command, count);   
        if(streq(command[0],"rfd")==0)         rfd(command, count);
    }
    if(count == 3) {
        if(streq(command[0],"cbeep")==0)       cbeep(command, count);
        if(streq(command[0],"rdram")==0)       rdram(command, count);
    }
}

