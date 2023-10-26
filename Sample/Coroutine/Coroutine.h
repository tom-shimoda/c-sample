#ifndef C_SAMPLE_COROUTINE_H
#define C_SAMPLE_COROUTINE_H

#define co_begin \
static int __state = 0; \
switch(__state){ \
case 0:

#define co_yield() \
do { \
__state = __LINE__; \
return; \
case __LINE__: \
break; \
} while(0);

#define co_end \
__state = __LINE__; \
}

#endif //C_SAMPLE_COROUTINE_H