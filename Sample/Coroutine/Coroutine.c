#include <stddef.h>
#include "Coroutine.h"

static Coroutine coroutinePool[30];

#define ARRAYLEN(_a) (sizeof(_a)/sizeof(_a[0]))

Coroutine* GetCoroutineFromPool()
{
    for (int i = 0; i < ARRAYLEN(coroutinePool); ++i)
    {
        if (coroutinePool[i].isUse) continue;

        return &coroutinePool[i];
    }

    // ASSERT: コルーチンプールの空きがありません。要素数を増やしてください。
}

void Coroutine_Init()
{
    for (int i = 0; i < ARRAYLEN(coroutinePool); ++i)
    {
        coroutinePool[i].isUse = false;
        coroutinePool[i].state = -1;
        coroutinePool[i].func = NULL;
        coroutinePool[i].onEnd = NULL;
    }
}

bool Coroutine_IsRunning(Coroutine* coroutine)
{
    if (coroutine == NULL) return false;

    return coroutine->state >= 0;
}

Coroutine* StartCoroutine(void (* func)(Coroutine*), void (* onEnd)())
{
    Coroutine* coroutine = GetCoroutineFromPool();

    coroutine->isUse = true;
    coroutine->state = 0;
    coroutine->func = func;
    coroutine->onEnd = onEnd;

    return coroutine;
}

void StopCoroutine(Coroutine* coroutine)
{
    if (coroutine == NULL) return;

    // 終了時コールバック発火
    coroutine->onEnd();

    coroutine->isUse = false;
    coroutine->state = -1;
    coroutine->func = NULL;
    coroutine->onEnd = NULL;
}

void Coroutine_Update()
{
    for (int i = 0; i < ARRAYLEN(coroutinePool); ++i)
    {
        if (!coroutinePool[i].isUse) return;

        coroutinePool[i].func(&coroutinePool[i]);
    }
}

int GetRunningCoroutineCount()
{
    int res = 0;
    for (int i = 0; i < ARRAYLEN(coroutinePool); ++i)
    {
        if (!coroutinePool[i].isUse) continue;

        res++;
    }
    return res;
}

