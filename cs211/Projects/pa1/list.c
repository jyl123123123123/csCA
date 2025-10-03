#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main(int argc, char* argv[])
{
    //insert: adds an integer n to the list
    //delete: removes an integer n from the list.

    /*
    char input[100];
    scanf("%s", input);
    printf("Input is: %s\n", &input[0]);

    char input[100];
    fgets(input, sizeof(input), stdin);
    printf("The input is: %s\n", inpSut);
    */

    int value;
    char input;

    Node* head = NULL;

    while(1)
    {
        //scanf(" %c", &input);↓
        //添加空格原因：上次输入剩余的\n会被读进去
        //添加空格后" %c" scanf会自动跳过空格，回车，Tab等空白字符，只读真正的字符输入
        if(scanf(" %c", &input) == EOF)
        {
            break;//检测到EOF的时候不会读入，可以用crtl D退出了
        }
        if(input == 'i')
        {
            if(scanf("%d", &value) == EOF)
            {
                break;
            }
            insertInIncreasingNumericOrder(&head, value);
        }
        else if(input == 'd')
        {
            if(scanf("%d", &value) == EOF)
            {
                break;
            }
            deleteValue(&head, value);
        }
        
        printList(head);
    }
    
}