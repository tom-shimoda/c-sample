#include <stdio.h>

#include "CoroutineSample.h"
#include "Coroutine.h"

static Coroutine* coroutine1;

static void StartGreeting(Coroutine* coroutine)
{
    static int counter = 0;

    co_begin;
            printf("hello world!!\n");
            co_waitForFrame(5); // 5フレーム待機

            printf("hi world!\n");
            co_waitForFrame(5); // 5フレーム待機

            printf("hi again.\n");
            // 途中で止める例
            if (counter == 3)
            {
                StopCoroutine(coroutine); // コルーチン終了
                return;
            }
            co_waitForFrame(5); // 5フレーム待機

            printf("hi\n");
            co_waitForFrame(5); // 5フレーム待機

            printf(":)\n");
    co_end;
}

static void OnEndGreeting()
{
    coroutine1 = NULL;
}

void CoroutineSample_Init()
{
    // コルーチン初期化
    Coroutine_Init();

    // コルーチン開始
    if (!Coroutine_IsRunning(coroutine1))
    {
        coroutine1 = StartCoroutine(StartGreeting, OnEndGreeting);
    }
}

void CoroutineSample_Update()
{
    // コルーチン更新
    Coroutine_Update();
}

void CoroutineSample_Exit()
{
    // コルーチン停止
    StopCoroutine(coroutine1);
}
