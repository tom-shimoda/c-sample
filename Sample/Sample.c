#ifdef WINDOWS
#include <stdio.h>
#elif MAC
#include <printf.h>
#endif

#include "Sample.h"
#include "Object-oriented/Object-oriented.h"
#include "Thread/Thread.h"
#include "Math/Rotate2D.h"
#include "Interface/InterfaceSample.h"
#include "Coroutine/CoroutineSample.h"
#include "List/ListSample.h"

void Sample_DoIt(SampleType type)
{
    switch (type)
    {
        case ObjectOriented:
            // オブジェクト指向
            printf("=== ObjectOrientedSample ===\n");
            ObjectOrientedSample();
            break;
        case Thread:
            /*
            // スレッド
            printf("=== BadThreadSample ===\n");
            BadThreadSample();

            printf("=== GoodThreadSample ===\n");
            GoodThreadSample();

            printf("=== SemaphoreSample ===\n");
            SemaphoreSample();
             */
            break;
        case Math:
            // 数学
            printf("=== Math ===\n");
            Rotate2DSample(); // 複素数平面回転
            break;
        case Interface:
            printf("=== Interface ===\n");
            InterfaceSample();
            break;
        case List:
            printf("=== List ===\n");
            ListSample();
            break;
        default:
            break;
    }
}

void Sample_DoEveryFrame(SampleType type)
{
    switch (type)
    {
        case Coroutine:
            // Coroutine
            CoroutineSample();
            break;
        default:
            break;
    }
}
