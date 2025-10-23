#include <stdio.h>
#include <stdlib.h>

void transposeMatrix(double**, double**, int, int);
void multiplyMatrix(double**, double**, double**, int, int, int);
void guassJordan(double**, double**, int);

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <training_file> <data_file>\n", argv[0]);
        return 1;
    }


    FILE* fp = fopen(argv[1], "r");
    if (!fp) { perror("training file"); return 1; }

    int k, n;
    char label[10];
    fscanf(fp, "%s", label);
    fscanf(fp, "%d", &k);
    fscanf(fp, "%d", &n);


    double** M = malloc(n * sizeof(double*));
    double** Y = malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        M[i] = malloc((k + 1) * sizeof(double));
        Y[i] = malloc(sizeof(double));
    }

    
    for (int i = 0; i < n; i++) {
        M[i][0] = 1.0;
        for (int j = 1; j <= k; j++)
            fscanf(fp, "%lf", &M[i][j]);
        fscanf(fp, "%lf", &Y[i][0]);
    }
    fclose(fp);

    
    double** MT = malloc((k + 1) * sizeof(double*));      // (k+1)×n
    double** product = malloc((k + 1) * sizeof(double*)); // (k+1)×(k+1)
    double** inv = malloc((k + 1) * sizeof(double*));     // (k+1)×(k+1)
    double** product1 = malloc((k + 1) * sizeof(double*));// (k+1)×n
    double** W = malloc((k + 1) * sizeof(double*));       // (k+1)×1

    for (int i = 0; i < k + 1; i++) {
        MT[i] = malloc(n * sizeof(double));
        product[i] = malloc((k + 1) * sizeof(double));
        inv[i] = malloc((k + 1) * sizeof(double));
        product1[i] = malloc(n * sizeof(double));
        W[i] = malloc(sizeof(double));
    }

    // XT = transpose(X)
    transposeMatrix(M, MT, n, k + 1);

    // XᵀX
    multiplyMatrix(MT, M, product, k + 1, n, k + 1);

    // (XᵀX)^(-1)
    guassJordan(inv, product, k + 1);

    // (XᵀX)^(-1)Xᵀ
    multiplyMatrix(inv, MT, product1, k + 1, k + 1, n);

    // W = ((XᵀX)^(-1)Xᵀ)Y
    multiplyMatrix(product1, Y, W, k + 1, n, 1);

    // ========== Prediction Part ==========
    FILE* fq = fopen(argv[2], "r");
    if (!fq) { perror("data file"); return 1; }

    int k2, m;
    char dataLabel[10];
    fscanf(fq, "%s", dataLabel);
    fscanf(fq, "%d", &k2);
    fscanf(fq, "%d", &m);

    double** given = malloc(m * sizeof(double*));
    double** prediction = malloc(m * sizeof(double*));
    for (int i = 0; i < m; i++) {
        given[i] = malloc((k + 1) * sizeof(double));
        prediction[i] = malloc(sizeof(double));
        given[i][0] = 1.0;
        for (int j = 1; j <= k; j++)
            fscanf(fq, "%lf", &given[i][j]);
    }
    fclose(fq);


    multiplyMatrix(given, W, prediction, m, k + 1, 1);

    for (int i = 0; i < m; i++)
        printf("%.0f\n", prediction[i][0]);



    for (int i = 0; i < n; i++) {
        free(M[i]);
        free(Y[i]);
    }
    free(M);
    free(Y);

    for (int i = 0; i < k + 1; i++) {
        free(MT[i]);
        free(product[i]);
        free(inv[i]);
        free(product1[i]);
        free(W[i]);
    }
    free(MT);
    free(product);
    free(inv);
    free(product1);
    free(W);

    for (int i = 0; i < m; i++) {
        free(given[i]);
        free(prediction[i]);
    }
    free(given);
    free(prediction);

    return 0;
}


void transposeMatrix(double** x, double** xt, int n, int m) {
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            xt[j][i] = x[i][j];
}

void multiplyMatrix(double** a, double** b, double** c, int aRows, int aCols, int bCols) {
    for (int i = 0; i < aRows; i++)
        for (int j = 0; j < bCols; j++) {
            double sum = 0.0;
            for (int k = 0; k < aCols; k++)
                sum += a[i][k] * b[k][j];
            c[i][j] = sum;
        }
}

void guassJordan(double** N, double** M, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            N[i][j] = (i == j) ? 1.0 : 0.0;

    for (int p = 0; p < n; p++) {
        double f = M[p][p];
        for (int j = 0; j < n; j++) {
            M[p][j] /= f;
            N[p][j] /= f;
        }
        for (int i = 0; i < n; i++) {
            if (i != p) {
                double factor = M[i][p];
                for (int j = 0; j < n; j++) {
                    M[i][j] -= factor * M[p][j];
                    N[i][j] -= factor * N[p][j];
                }
            }
        }
    }
}
