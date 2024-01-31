#ifndef C_SAMPLE_COROUTINE_H
#define C_SAMPLE_COROUTINE_H

#include <stdbool.h>

typedef struct Coroutine_
{
    bool isUse;
    int state; // 現在の進行状態 (-1なら停止中)
    void (* func)(struct Coroutine_* coroutine);
    void (* onEnd)(); // 終了時コールバック
} Coroutine;

// コルーチン初期化
void Coroutine_Init();

// コルーチン動作中か
bool Coroutine_IsRunning(Coroutine* coroutine);

// コルーチン開始
Coroutine* StartCoroutine(void (* func)(Coroutine* coroutine), void (* onEnd)());

// コルーチン停止
void StopCoroutine(Coroutine* coroutine);

// コルーチン更新
void Coroutine_Update();

// 動作中のコルーチン数を取得 (主にDebug用)
int GetRunningCoroutineCount();

#define co_begin \
static int __waitCounter = 0; \
switch(coroutine->state){ \
    case -1: \
        break; \
    case 0:

#define co_yield() \
do { \
    coroutine->state = __LINE__; \
    return; \
    case __LINE__: \
        break; \
} while(0);

#define co_waitForFrame(n) \
do { \
    coroutine->state = __LINE__; \
    __waitCounter = n; \
    return; \
    case __LINE__: \
        __waitCounter--; \
        if(__waitCounter <= 0){    \
            __waitCounter = 0; \
            break; \
        } else{ \
            return; \
        } \
} while(0);

#define co_end \
    StopCoroutine(coroutine); \
}

#define co_repeat \
    coroutine->state = 0; \
}

#endif //C_SAMPLE_COROUTINE_H
