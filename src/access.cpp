#include"stdio.h"
#include"unistd.h"
#include "string.h"
#define fileNAME1 "test"
#define fileNAME2 "./liang"
int main(void)
{
    char name[BUFSIZ];//�ļ�����
    int flag = 1;//�˳���־,0 exit
    printf("input you file(�ɰ���·��,EOF�˳�):");
    scanf("%s", name);
    if (strcmp(name, "EOF") == 0)
    {
        flag = 0;
    }
    while (flag)
    {
        if (access(name, F_OK) == 0)
        {
            printf("file exit\n");
            if (access(name, R_OK | W_OK) == 0)
            {
                printf("file is read and write\n");
            }
            else
                printf("file not read and no write\n");
            if (access(name, X_OK) == 0)
            {
                printf("excute\n");
            }
            else
                printf("can not excute\n");
        }
        else
            printf("file not exit\n");
        printf("\n input file (�ɰ���·��,EOF�˳�):");
        scanf("%s", name);
        if (strcmp(name, "EOF") == 0)
        {
            flag = 0;
        }
    }//while
    printf("\t\t\t exit\n");
    return 0;
}