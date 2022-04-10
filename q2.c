#include <stdio.h>
#include <string.h>

int main()
{
    // Addtion,Subtraction and Multiplication of a 3*3 matrix.
    int a[3][3], b[3][3], sum[3][3], diff[3][3], mult[3][3];
    int i, j;
    printf("Enter the elements of first matrix:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the elements of second matrix:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("b[%d][%d] = ", i, j);
            scanf("%d", &b[i][j]);
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            diff[i][j] = a[i][j] - b[i][j];
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            mult[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
        }
    }

    // Print results in tabular form
    printf("\n\nAddition of two matrices:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }
    printf("\n\nSubtraction of two matrices:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", diff[i][j]);
        }
        printf("\n");
    }
    printf("\n\nMultiplication of two matrices:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", mult[i][j]);
        }
        printf("\n");
    }
}