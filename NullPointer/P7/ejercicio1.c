#include <stdio.h>

int main()
{
    int N = 1, M = 1;
    //ReadSize
    printf("Dame el tamano de N\n");
    scanf("%d", &N);
    printf("Dame el tamano de M\n");
    scanf("%d", &M);
    float A[N][M], X[N], Z[N];
    //ReadData
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("Matrix A - Position [%d, %d]\n", i+1, j+1);
            scanf("%f", &A[i][j]);
        }
    }
    for(int i = 0; i < N; i++){
        printf("Vector X - Position [%d]\n", i+1);
        scanf("%f", &X[i]);
    }
    //CalculateResult
    for(int i = 0; i < N; i++){
        float sumador = 0;
        for(int j = 0; j < M; j++){
            sumador += A[i][j] * X[i];
        }
        Z[i] = sumador;
    }
    //PrintResult
    printf("\n\n\nResults\n");
    for(int i = 0; i < N; i++){
        printf("%f\n", Z[i]);
    }
    return 0;
}