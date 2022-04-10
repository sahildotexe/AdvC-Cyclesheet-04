#include <stdio.h>
#include <string.h>

int printSum(int n)
{
    // Sum of first n natural numbers using recursion
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n + printSum(n - 1);
    }
}

int printFact(int n)
{
    // Factorial of n using recursion
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * printFact(n - 1);
    }
}

// Fibonacci using recursion
int printFibonacci(int i)
{
    if (i == 0)
        return 0;
    else if (i == 1)
        return 1;
    else
        return (printFibonacci(i - 1) + printFibonacci(i - 2));
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    // Function to print sum of numbers using recursion
    int sum = printSum(n);
    printf("Sum of first %d natural numbers is %d\n", n, sum);
    int fact = printFact(n);
    printf("Product of %d natural numbers is %d\n", n, fact);
    printf("Fibonacci of %d is :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", printFibonacci(i));
    }
    printf("\n");
}