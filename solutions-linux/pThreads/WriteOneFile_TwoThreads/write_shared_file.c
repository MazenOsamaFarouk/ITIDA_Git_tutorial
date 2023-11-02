#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int count = 0;  /*just a counter to see if mutex lock doing anything*/
pthread_mutex_t mutex; /*creating mutex*/
FILE *SharedFile = NULL;

void *Thread_WriteSharedFile(void *arg);

int main(void)
{
    pthread_mutex_init(&mutex, NULL); /*initializing mutex*/

    SharedFile = fopen("SHARED_FILE.txt", "w");
    if (SharedFile == NULL)
    {
        fclose(SharedFile);
        exit(1);
    }

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, Thread_WriteSharedFile, NULL);
    pthread_create(&thread2, NULL, Thread_WriteSharedFile, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    /*just learning mutexs with pthreads*/
    if (count == 60000)
    {
        printf("SAFE\n");
    }
    else
    {
        printf("NOT SAFE\n");
    }

    printf("count: %d\n", count); /*to check how many writes i missed without a mutex can comment the mutex in code :D*/
    /*count should be 60000 with mutex and less without the use of mutex*/

    fclose(SharedFile);
    pthread_mutex_destroy(&mutex); /*destroy mutex*/

    return 0;
}

void *Thread_WriteSharedFile(void *arg)
{
    for (int i = 0; i < 30000; i++)
    {
        pthread_mutex_lock(&mutex); /*lock shared resource*/ /*can comment this to see the missed writes*/

        fprintf(SharedFile, "SharedFile_Line[%d].\n", i + 1);
        count++;

        pthread_mutex_unlock(&mutex); /*unlock shared resource*/ /*can comment this to see the missed writes*/
    }
}