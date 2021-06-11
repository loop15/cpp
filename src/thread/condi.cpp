#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;/*��ʼ��������*/
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;/*��ʼ����������*/
void *thread1(void *);
void *thread2(void *);
int i = 1;
int main(void)
{
    pthread_t t_a;
    pthread_t t_b;
    pthread_create(&t_a, NULL, thread1, (void *)NULL); /*��������t_a*/
    pthread_create(&t_b, NULL, thread2, (void *)NULL); /*��������t_b*/
    pthread_join(t_a, NULL);/*�ȴ�����t_a����*/
    pthread_join(t_b, NULL);/*�ȴ�����t_b����*/
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    exit(0);
}
void *thread1(void *junk)
{
    for (i = 1; i <= 6; i++)
    {
        pthread_mutex_lock(&mutex);/*��ס������*/
        printf("thread1: lock %d\n", __LINE__);
        if (i % 3 == 0)
        {
            printf("thread1:signal 1  %d\n", __LINE__);
            pthread_cond_signal(&cond);/*�����ı䣬�����źţ�֪ͨt_b����*/
            printf("thread1:signal 2  %d\n", __LINE__);
            sleep(1);
        }
        pthread_mutex_unlock(&mutex);/*����������*/
        printf("thread1: unlock %d\n", __LINE__);
        sleep(1);
    }
}
void *thread2(void *junk)
{
    while (i < 6)
    {
        pthread_mutex_lock(&mutex);
        printf("thread2: lock %d\n", __LINE__);
        if (i % 3 != 0)
        {
            printf("thread2: wait 1  %d\n", __LINE__);
            pthread_cond_wait(&cond, &mutex); /*����mutex�����ȴ�cond�ı�*/
            printf("thread2: wait 2  %d\n", __LINE__);
        }
        pthread_mutex_unlock(&mutex);
        printf("thread2: unlock %d\n\n", __LINE__);
        sleep(1);
    }
}