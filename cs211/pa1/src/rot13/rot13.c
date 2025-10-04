#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    //把string里的每个字母都分别转换成数字(int)，然后再转换成13位之后的ASCII值，再转换回去。
    int len = strlen(argv[1]);
    for(int i = 0; i < len; i++)
    {
        int ptr = (int)argv[1][i];
        if((ptr >= 65 && ptr <= 77) || (ptr >= 97 && ptr <= 109))
        {
            ptr = ptr + 13;
            argv[1][i] = (char)ptr;
        }
        else if((ptr >= 78 && ptr <= 90) || (ptr >= 110 && ptr <= 122))
        {
            ptr = ptr - 13;
            argv[1][i] = (char)ptr;
        }
    }
    printf("%s\n", argv[1]);
    return 0;
}