#include <stdio.h>/*this is a head file; #include is a pre-executed command, which is used to import head files.
If the compiler didn't find a stdio.h head file, an error will occur.*/

int main()/*All c programs need to include main(). Codes execute from main() function*/
/*when int main() occurs, the return type is int*/
{
    /*my first c program*/
    printf("Hello, world! \n");/*printf() function is declimed in stdio.h file*/
    /*printf("可执行程序 %s, 参数个数为[%d], 运行输出: [%s]\n")*/
    return 0;/*This is for exit the program*/
}

/*To compile --> gcc fileName.c  then you can have a executable program --> a.out, conduct the program --> ./a.out*/