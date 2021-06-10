#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/prctl.h>//系统调用
pthread_mutex_t mutex ;

void *print_msg(void *arg)
{
    int i = 0;
    char name[32];
    pthread_t tid = pthread_self();
    prctl(PR_SET_NAME, (unsigned long)"xx");
    prctl(PR_GET_NAME, (unsigned long)name);
    pthread_mutex_lock(&mutex);
    for (i = 0; i < 15; i++)
    {
        printf("thrad=%p name = %s output : %d\n", tid, name, i);
        usleep(100);
    }
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t id1;
    pthread_t id2;
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&id1, NULL, print_msg, NULL);
    pthread_create(&id2, NULL, print_msg, NULL);
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    pthread_mutex_destroy(&mutex);
    return 1;
}
