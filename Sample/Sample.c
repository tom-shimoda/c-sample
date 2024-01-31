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
        case SampleType_ObjectOriented:
            // オブジェクト指向
            printf("=== ObjectOrientedSample ===\n");
            ObjectOrientedSample();
            break;
        case SampleType_Thread:
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
        case SampleType_Math:
            // 数学
            printf("=== SampleType_Math ===\n");
            Rotate2DSample(); // 複素数平面回転
            break;
        case SampleType_Interface:
            printf("=== SampleType_Interface ===\n");
            InterfaceSample();
            break;
        case SampleType_List:
            printf("=== SampleType_List ===\n");
            ListSample();
            break;
        default:
            break;
    }
}

void Sample_Init(SampleType type)
{
    switch (type)
    {
        case SampleType_Coroutine:
            CoroutineSample_Init();
            break;
        default:
            break;
    }
}

void Sample_Update(SampleType type)
{
    switch (type)
    {
        case SampleType_Coroutine:
            CoroutineSample_Update();
            break;
        default:
            break;
    }
}

void Sample_Exit(SampleType type)
{
    switch (type)
    {
        case SampleType_Coroutine:
            CoroutineSample_Exit();
            break;
        default:
            break;
    }
}
