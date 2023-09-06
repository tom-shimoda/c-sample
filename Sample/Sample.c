#include <printf.h>
#include "Sample.h"
#include "Object-oriented/Object-oriented.h"
#include "Thread/Thread.h"

typedef enum
{
    ObjectOriented,
    Thread,
} SampleType;

void Sample_DoIt()
{
    SampleType sampleType = Thread;

    switch (sampleType)
    {
        case ObjectOriented:
            // オブジェクト指向
            printf("=== ObjectOrientedSample ===\n");
            ObjectOrientedSample();
            break;
        case Thread:
            // スレッド
            printf("=== BadThreadSample ===\n");
            BadThreadSample();
            
            printf("=== GoodThreadSample ===\n");
            GoodThreadSample();
            break;
    }
}