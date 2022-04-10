#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[10], n, i;
    system("cls");
    printf("Enter the number to convert: ");
    scanf("%d", &n);
    if (n < 100 || n > 999)
    {
        printf("Invalid number(Enter a 3 digit number.");
        return 0;
    }
    else
    {
        printf("\nReverse Binary of Given Number is =");
        for (i = 0; n > 0; i++)
        {
            a[i] = n % 2;
            printf(" %d ", a[i]);

            n = n / 2;
        }
    }

    return 0;
}