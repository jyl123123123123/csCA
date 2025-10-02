#include "stdio.h"
#include "stack.h"
#include <string.h>


int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("%s\n", "Invalid number of arguments.");
        return 1;
    }

    //if balanced, print nothing and exit with status EXIT_SUCCESS
    //if not valanced, print error message and exit with status EXIT_FAILURE
    //error message: print the index for the unexpected delimiter and the closing delimiter encourtered
    //print "open: 'the close delimiters needed'"

    Stack s;
    init(&s);

    for(int i = 0; i < strlen(argv[1]); i++) 
    {
        switch(argv[1][i])
        {
            case '(':
                push(&s, argv[1][i]);
                break;
            
            case '[':
                push(&s, argv[1][i]);
                break;

            case '{':
                push(&s, argv[1][i]);
                break;

            case '<':
                push(&s, argv[1][i]);
                break;

            case ')':
                if(peek(&s) != '(' )
                {
                    printf("%d: %c\n", i, argv[1][i]);
                    
                    return EXIT_FAILURE;
                }
                pop(&s);

            case ']':
                if(peek(&s) != '[' )
                {
                    printf("%d: %c\n", i, argv[1][i]);
                
                    return EXIT_FAILURE;
                }
                pop(&s);

            case '}':
                if(peek(&s) != '{' )
                {
                    printf("%d: %c\n", i, argv[1][i]);
                    
                    return EXIT_FAILURE;
                }
                pop(&s);

            case '>':
                if(peek(&s) != '<' )
                {
                    printf("%d: %c\n", i, argv[1][i]);
                    
                    return EXIT_FAILURE;
                }
                pop(&s);
        }
    }

    if(!isEmpty(&s))
    {
        char k[100];
        int index = 0;
        while(!isEmpty(&s))
        {
            switch(peek(&s))
            {
                case '(' :
                    k[index++] = ')';
                    pop(&s);
                    break;
                    
                case '[' :
                    k[index++] = ']';
                    pop(&s);
                    break;

                case '{' :
                    k[index++] = '}';
                    pop(&s);
                    break;

                case '<' :
                    k[index++] = '>';
                    pop(&s);
                    break;
            }
        }
        k[index] = '\0';
        printf("open:%s\n", k);
    }
    
}
