#ifndef C_SAMPLE_THREAD_H
#define C_SAMPLE_THREAD_H

static void* BadFunc(void* arg);

void BadThreadSample();

static void* GoodFunc(void* arg);

void GoodThreadSample();

static void* SemaphoreFunc(void* arg);

void SemaphoreSample();

#endif //C_SAMPLE_THREAD_H
