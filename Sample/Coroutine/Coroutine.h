#ifndef C_SAMPLE_COROUTINE_H
#define C_SAMPLE_COROUTINE_H

#define co_begin \
static int __waitCounter = 0; \
switch(*__state){ \
    case -1: \
        break; \
    case 0:

#define co_yield() \
do { \
    *__state = __LINE__; \
    return; \
    case __LINE__: \
        break; \
} while(0);

#define co_waitForFrame(n) \
do { \
    *__state = __LINE__; \
    __waitCounter = n; \
    return; \
    case __LINE__: \
        __waitCounter--; \
        if(__waitCounter <= 0){    \
            __waitCounter = 0; \
            break; \
        } else{ \
            return; \
        } \
} while(0);

#define co_end \
    *__state = -1; \
}

#define co_repeat \
    *__state = 0; \
}

#endif //C_SAMPLE_COROUTINE_H
