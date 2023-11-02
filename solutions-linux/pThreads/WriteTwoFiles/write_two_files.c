#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *Thread_WriteFile1(void *arg);
void *Thread_WriteFile2(void *arg);

int main(void)
{
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, Thread_WriteFile1, NULL);
    pthread_create(&thread2, NULL, Thread_WriteFile2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    return 0;
}

void *Thread_WriteFile1(void *arg)
{
    FILE *FILE1 = fopen("FILE1.txt", "w");

    for (int i = 0; i < 20; i++)
    {
        fprintf(FILE1, "FILE1_Line[%d].\n", i+1);
        /*fflush saves changes to the physical file without the need to close the file*/
        fflush(FILE1); /*just stole that from mohaned for simpler live monitoring without opening and closing */
        sleep(1); /*just so i can monitor it with tail -f*/
    }

    fclose(FILE1);
}

void *Thread_WriteFile2(void *arg)
{
    FILE *FILE2 = fopen("FILE2.txt", "w");

    for (int i = 0; i < 20; i++)
    {
        fprintf(FILE2, "FILE2_Line[%d].\n", i+1);
        /*fflush saves changes to the physical file without the need to close the file*/
        fflush(FILE2); /*just stole that from mohaned for simpler live monitoring without opening and closing */
        sleep(1); /*just so i can monitor it with tail -f*/
    }

    fclose(FILE2);
}