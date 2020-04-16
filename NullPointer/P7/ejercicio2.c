/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

void readMatrix(int matrix[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("Position [%d, %d]\n", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[3][3]){
    printf("\n\nTable\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void validateMagicBox(int matrix[3][3]){
    //Check Columns
    for(int i = 0; i < 3; i++){
        int sum = matrix[i][0] + matrix[i][1] + matrix[i][2];
        if(sum == 15){
            printf("Column %d sum is 15\n", i+1);
        }
    }
    //Check Rows
    for(int i = 0; i < 3; i++){
        int sum = matrix[0][i] + matrix[1][i] + matrix[2][i];
        if(sum == 15){
            printf("Row %d sum is 15\n", i+1);
        }
    }
    //Check Diagonal
    int sumSlash = matrix[0][2] + matrix[1][1] + matrix[2][0];
    int sumBackslash = matrix[0][0] + matrix[1][1] + matrix[2][2];
    if(sumSlash == 15){
        printf("Diagonal / sum is 15\n");
    }
    if(sumBackslash == 15){
        printf("Diagonal \\ sum is 15\n");
    }
}

int main()
{
    int matrix[3][3];
    readMatrix(matrix);
    printMatrix(matrix);
    validateMagicBox(matrix);
    return 0;
}
