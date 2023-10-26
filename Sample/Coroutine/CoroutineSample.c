#include <stdio.h>

#include "CoroutineSample.h"
#include "Coroutine.h"

void DoEveryFrame2(int* __state)
{
    co_begin;
            printf("hello world!!\n");
            co_yield();

            printf("hi world!\n");
            co_waitForFrame(2);

            printf("hi again.\n");
            co_waitForFrame(2);

            printf("hi\n");
            co_yield();

            printf(":)\n");
    co_end;
}

void CoroutineSample()
{
    static int frameCounter = 1;
    static int state;
    
    if (frameCounter++ > 5) state = -1; // -1にすれば止まる (関数自体は呼ばれ続ける点に注意)
    DoEveryFrame2(&state);
}

