// Write a program that accepts an integer 'n' and prints the pattern.if n = 3, the pattern is,
//     3
//   3 2 3
// 3 2 1 2 3
//   3 2 3
//     3

#include <stdio.h>
int main()
{
    int n, i, j;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    //     3
    //   3 2 3
    // 3 2 1 2 3
    //   3 2 3
    //     3
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i + j < n - 1)
            {
                printf("%d ", i + j + 1);
            }
            else
            {
                printf("%d", i + j + 1);
            }
        }
        printf("\n");
    }
    return 0;
}