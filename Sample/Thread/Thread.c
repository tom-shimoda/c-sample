#include <printf.h>
#include <pthread.h>
#include <sys/semaphore.h>
#include <sys/fcntl.h>

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

    pthread_mutex_destroy(&lock);
}

// Semaphore
long semaphoreCounter = 0;
sem_t* semaphore;

void* SemaphoreFunc(void* arg)
{
    long arg_ = *((long*)arg);
    for (long i = 0; i < arg_; i++)
    {
        sem_wait(semaphore);
        semaphoreCounter++;
        sem_post(semaphore);
    }

    return NULL;
}

void SemaphoreSample()
{
    long num = 1000000;
    pthread_t tid1, tid2;
    const char* sem_name = "/semaphore";
    
//    sem_init(semaphore, 0, 1); // Macでは名前無しセマフォは未サポート
    if ((semaphore = sem_open(sem_name, O_CREAT | O_EXCL, 0644, 1)) == SEM_FAILED)
    {
        perror("sem_open");
        return;
    }

    if (pthread_create(&tid1, NULL, SemaphoreFunc, (void*)&num) != 0)
    {
        fprintf(stderr, "Error: cannot create thread.\n");
        return;
    }
    pthread_create(&tid2, NULL, SemaphoreFunc, (void*)&num);

    if (pthread_join(tid1, NULL))
    {
        fprintf(stderr, "Error: cannot join thread.\n");
        return;
    }
    pthread_join(tid2, NULL);

    if (semaphoreCounter != num * 2)
        printf("BOOM! semaphoreCounter = %ld\n", semaphoreCounter);
    else
        printf("OK semaphoreCounter=%ld\n", semaphoreCounter);

    sem_close(semaphore);
    sem_unlink(sem_name);
}

