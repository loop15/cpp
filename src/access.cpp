#include"stdio.h"
#include"unistd.h"
#include "string.h"
#define fileNAME1 "test"
#define fileNAME2 "./liang"
int main(void)
{
    char name[BUFSIZ];//文件名字
    int flag = 1;//退出标志,0 exit
    printf("input you file(可包含路径,EOF退出):");
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
        printf("\n input file (可包含路径,EOF退出):");
        scanf("%s", name);
        if (strcmp(name, "EOF") == 0)
        {
            flag = 0;
        }
    }//while
    printf("\t\t\t exit\n");
    return 0;
}