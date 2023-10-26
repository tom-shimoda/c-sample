#include <stdbool.h>
#include <stdio.h>
#include "Sample/Sample.h"

int main(void)
{
//    Sample_DoIt(ObjectOriented);
//    Sample_DoIt(Thread);
//    Sample_DoIt(Math);
//    Sample_DoIt(Interface);
//    Sample_DoIt(Coroutine);

    // 無限ループの例
    int frameCounter = 0;
    for (int i = 0; i < 10; ++i)
    {
        printf("=== frame : %d ===\n", frameCounter++);
        Sample_DoEveryFrame(Coroutine);
    }

    return 0;
}