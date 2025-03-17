/* Allocates one page of size size. Yes, I (llcch) wrote this */
void *XK_Malloc(uint32_t size) {
    if(pageptr - size < 0)
        return NULL;
    //if((char*)(pageptr+1) != 0)
    //    return NULL;

    clearBuffer((void*)pageptr, size);

    pageptr += size;

    return (void*)(pageptr - size);
}

/* Frees one page of size size */
void XK_Free(uint32_t size) {
    if(pageptr - size < 0)
        return;

    clearBuffer((void*)pageptr, size);

    pageptr -= size;
}
