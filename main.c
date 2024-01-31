#include <stdio.h>
#include "Sample/Sample.h"

int main(void)
{
    // ワンショット処理
//    Sample_DoIt(SampleType_ObjectOriented);
//    Sample_DoIt(SampleType_Thread);
//    Sample_DoIt(SampleType_Math);
//    Sample_DoIt(SampleType_Interface);
//    Sample_DoIt(SampleType_List);


    // 初期化
    Sample_Init(SampleType_Coroutine);

    // 無限ループ (のつもり)
    int frameCounter = 0;
    int roopCount = 30;
    for (int i = 0; i < roopCount; ++i)
    {
        printf("=== frame : %d ===\n", frameCounter++);
        Sample_Update(SampleType_Coroutine);
    }

    // 終了処理
    Sample_Exit(SampleType_Coroutine);

    return 0;
}