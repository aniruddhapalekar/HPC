#include<stdio.h>
#include<omp.h>

int fib(int n)
{
    int arr[n+2];
    int i;
    arr[0] = 0;
    arr[1] = 1;
    #pragma omp ordered
        for (i = 2; i <= n; i++)
        {
            arr[i] = arr[i-1] + arr[i-2];
        }
    return arr[n];
}

int main ()
{
    int n=0;
    printf("Enter a number : ");
    scanf("%d",&n);
    printf("\n%dth Fibonacci number is : %d\n", n, fib(n));
    return 0;
}
