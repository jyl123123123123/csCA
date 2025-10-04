#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_char(const void* a, const void* b)
{
    return (*(const char*)a - *(const char*)b);
}

int main(int argc, char *argv[])
{
    //把所有字母重新排序，删去标点符号
    //用qsort
    int n = strlen(argv[1]);
    for(int i = 0; i < strlen(argv[1]); i++)
    {
        if(!(((int)argv[1][i] >= 65 && (int)argv[1][i] <= 90) || ((int)argv[1][i] >= 97 && (int)argv[1][i] <= 122)))
        {
            argv[1][i] = '~';
        }
        else if((int)argv[1][i]>=65 && (int)argv[1][i] <= 90)
        {
            argv[1][i] = (char)((int)argv[1][i] + 32);
        }
    }
    
    qsort(argv[1],n,sizeof(char),compare_char);
    for(int i = 9; i < strlen(argv[1]); i++)
    {
        if(!(((int)argv[1][i] >= 65 && (int)argv[1][i] <= 90) || ((int)argv[1][i] >= 97 && (int)argv[1][i] <= 122)))
        {
            argv[1][i] = '\0';
            break;      
            // hi
        }
    }
    printf("%s\n", argv[1]);
    return 0;
}
