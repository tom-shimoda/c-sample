#include <stdio.h>

#include "CoroutineSample.h"
#include "Coroutine.h"

// マクロ展開したらこうなる
void helloworld_DeployedMacro(void)
{
//    co_begin;
    static int __state = 0;
    switch (__state)
    {
        case 0:

            printf("hello world!!\n");
//            co_yield();
            do
            {
                __state = __LINE__;
                return;
                case __LINE__:
                    break;
            } while (0);

            printf("hi world!\n");
            co_yield();

            printf("hi again.\n");
            co_yield();

            printf("hi\n");
            co_yield();

            printf(":)\n");

//    co_end;
            __state = __LINE__;
    }
}

void DoEveryFrame()
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

// 舞フレーム呼び出し例
void CoroutineSample()
{
    DoEveryFrame();
}

