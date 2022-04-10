#include <stdio.h>
static int count = 0;

int fib(int n)
{
    // Count number of times the recursive function is called
    count++;
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("%dth Fibonacci value is : %d \n", n, fib(n));
    printf("Number of times fib() is called: %d\n", count);
    return 0;
}