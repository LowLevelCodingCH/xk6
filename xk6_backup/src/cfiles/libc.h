/* Memory Related */
void*    xk_malloc  (uint32_t size)                    {return XK_Malloc(size);}
void     xk_free    (uint32_t size)                    {XK_Free(size);}
void*    xk_mmap    (uint32_t size)                    {return XK_Malloc(size);}
void     xk_munmap  (uint32_t size)                    {XK_Free(size);}

/* Debug Related */
void     xk_printf  (char *fmt, ...)                   {printf(fmt);}
void     xk_panic   (BYTE *err, ERROR_CODE code)       {XK_Panic(err, code, FALSE);}

/* Command Related*/
void     xk_system  (char cmd[16][50], uint32_t count) {XK_SystemExecuteShellCommand(cmd, count);}

/* FS Related */
uint32_t xk_open    (char file[16])                    {return XK_GetFileIndex(FST_Entries, 256, file);}
void     xk_close   (uint32_t file)                    {}
void     xk_read    (uint32_t fd, char* buf)           {XK_ReadFileByIndex(FST_Entries, FST_Blocks, fd, buf);}
void     xk_xkfsctl (void)                             {XK_ReadXKFS();}

/* Program related */
void     xk_execve  (char file[16])                    {XK_ExecuteByFile(file);}

/* Process Related */
void     xk_kill    (uint32_t pid)                     {XK_RemoveTask(pid);}
void     xk_killall (void)                             {XK_RemoveAllTasks();}
uint32_t xk_getpid  (void)                             {klog_println("Not yet implemented: xk_getpid"); return 0;}
