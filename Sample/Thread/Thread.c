#include <printf.h>
#include <pthread.h>

// Bad --------------------------------
long badCounter = 0;

static void* BadFunc(void* arg)
{
    long arg_ = *((long*)arg);
    for (long i = 0; i < arg_; i++)
    {
        badCounter++;
    }

    return NULL;
}

void BadThreadSample()
{
    long num = 1000000;
    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, BadFunc, (void*)&num);
    pthread_create(&tid2, NULL, BadFunc, (void*)&num);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    if (badCounter != num * 2)
        printf("BOOM! badCounter = %ld\n", badCounter);
    else
        printf("OK badCounter=%ld\n", badCounter);
}


// Good --------------------------------
long goodCounter = 0;
pthread_mutex_t lock;

static void* GoodFunc(void* arg)
{
    long arg_ = *((long*)arg);
    for (long i = 0; i < arg_; i++)
    {
        pthread_mutex_lock(&lock);
        goodCounter++;
        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

void GoodThreadSample()
{
    long num = 1000000;
    pthread_t tid1, tid2;

    pthread_mutex_init(&lock, NULL);
    pthread_create(&tid1, NULL, GoodFunc, (void*)&num);
    pthread_create(&tid2, NULL, GoodFunc, (void*)&num);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    if (goodCounter != num * 2)
        printf("BOOM! goodCounter = %ld\n", goodCounter);
    else
        printf("OK goodCounter=%ld\n", goodCounter);

}



