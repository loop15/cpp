#include <stdio.h>
#include <pthread.h>
#include <sys/prctl.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void *tmain(void *arg)
{
    char name[32];
    prctl(PR_SET_NAME, (unsigned long)"xx");
    prctl(PR_GET_NAME, (unsigned long)name);
    printf("%s/n", name);
    while (1)
    {
        sleep(1);
    }
}
int main(void)
{
    pthread_t tid;
    pthread_create(&tid, NULL, tmain, NULL);
    pthread_join(tid, NULL);
    return 0;
}

/*
cw@SYS3:~/study/github/cpp/src$ ./prctl.out  &
[3] 2533
cw@SYS3:~/study/github/cpp/src$ ps -ef |grep xx
cw        2562 16464  0 09:08 pts/38   00:00:00 grep xx
*/
