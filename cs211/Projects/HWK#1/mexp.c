#include <stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
    //k*k matrix
    //non-negative n
    //compute M^n and prints the result
    //use malloc to allocte space for matrix
    //M^n->multiply M by itself n-1 times. M^3 = M*M*M; different for M^0
    //INPUT: first line = k
    //next K lines: k integers = M
    //final line = n

    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");
    if(!fp)
    {
        perror("error");
        return 1;
    }

    int k;
    fscanf(fp, "%d", &k);
    //printf("k = %d.\n", k);

    int** matrix = malloc(k * sizeof(int*));
    int** result = malloc(k * sizeof(int*));
    int** temp = malloc(k * sizeof(int*));

    for(int i = 0; i < k; i++)
    {
        matrix[i] = malloc(k * sizeof(int));
        result[i] = malloc(k * sizeof(int));
        temp[i] = malloc(k * sizeof(int));
    }

    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            fscanf(fp, "%d", &matrix[i][j]);
        }
    }

    int n;
    fscanf(fp, "%d", &n);
    //printf("n = %d.\n", n);

    fclose(fp);
    
    for (int i = 0; i < k; i++) 
    {
        for (int j = 0; j < k; j++)
        {
            result[i][j] = 0;
        }
        result[i][i] = 1;
    }

    for(int t = 0; t < n; t++)
    {
        for(int i = 0; i < k; i++)
        {
            for(int j = 0; j < k; j++)
            {
                int temp_ = 0;
                for(int l = 0; l < k; l++)
                {
                    temp_ = temp_ + result[i][l] * matrix[l][j];
                }
                temp[i][j] = temp_;
                //matrix[i] * matrix[j]
            }
        }
        for(int i = 0; i < k; i++)
        {
            for(int j = 0; j < k; j++)
            {
                result[i][j] = temp[i][j];
            }
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < k; i++)
    {
        free(matrix[i]);
        free(result[i]);
        free(temp[i]);
    }
    free(matrix);
    free(result);
    free(temp);
}