/* BIS types */
typedef char* BisTTY;

typedef enum {
    BIS_STATUS_SUCCESS             = 0,
    BIS_STATUS_UNINITIALIZED       = 1,
    BIS_STATUS_ALREADY_INITIALIZED = 2,
} BIS_STATUS;

typedef struct {
    BisTTY       tty;
    unsigned int cur;
    void         (*write)(char* a, char* s, unsigned int* c, unsigned int l);
    void         (*rescur)(unsigned int* c);
    void         (*setcur)(unsigned int* c, unsigned int n);
    void         (*clrscr)(char* a, char s, unsigned int* c);
} bis_tty;

/* BIS defs */
#define BIS_WIDTH  80
#define BIS_HEIGHT 25

/* BIS vars */
bis_tty tty;
bis_tty *ttyptr = &tty;

/* BIS funcs */
void bis_write(char* a, char *s, unsigned int* c, unsigned int l) {
    unsigned int ccur = *c;

    for(unsigned int i = 0; i < l; i++)
        a[(i * 2) + ccur] = s[i];
    *c += l*2;
}

void bis_rescur(unsigned int* c) {
    *c = 0;
}

void bis_setcur(unsigned int* c, unsigned int n) {
    *c = n;
}

void bis_clrscr(char* a, char s, unsigned int* c) {
    for(unsigned int i = 0; i < BIS_WIDTH*BIS_HEIGHT; i++)
        a[i*2] = s;
    *c = 0;
}

BIS_STATUS bis_init(void) {
    if(tty.tty != NULL)
        return BIS_STATUS_ALREADY_INITIALIZED;
    
    tty.tty = (char*)0xb8000;
    tty.cur = 0;

    tty.write  = &bis_write;
    tty.rescur = &bis_rescur;
    tty.setcur = &bis_setcur;
    tty.clrscr = &bis_clrscr;

    if(tty.tty == NULL)
        return BIS_STATUS_UNINITIALIZED;

    return BIS_STATUS_SUCCESS;
}

BIS_STATUS bis_exit(void) {
    if(tty.tty == NULL)
        return BIS_STATUS_UNINITIALIZED;

    tty.clrscr(tty.tty, ' ', &tty.cur);

    tty.tty    = NULL;
    tty.cur    = 0;
    tty.write  = NULL;
    tty.rescur = NULL;
    tty.setcur = NULL;
    tty.clrscr = NULL;

    return BIS_STATUS_SUCCESS;
}
