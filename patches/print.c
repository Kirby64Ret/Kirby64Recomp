#include "patches.h"
#include "misc_funcs.h"

#include <stdarg.h>

typedef char *outfun(char*,const char*,size_t);
extern int _Printf(outfun prout, char *arg, const char *fmt, va_list args);

void* proutPrintf(void* dst, const char* fmt, size_t size) {
    recomp_puts(fmt, size);
    return (void*)1;
}

int recomp_printf(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    int ret = _Printf(&proutPrintf, NULL, fmt, args);

    va_end(args);

    return ret;
}
