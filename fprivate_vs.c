#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define n 8

int main()
{

  int *a;
  int *b;
  a = (int *)malloc(n * sizeof(int));
  b = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
  {
    a[i] = i;
  }
  int x = 8, y = 33;
#pragma omp parallel for firstprivate(a, y)
  for (int i = 0; i < n; i++)
  {
    b[i] = a[i] + x;
    printf("Thread = %d\n", omp_get_thread_num());
    printf("i = %d\n", i);
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    y = i;
    printf("Thread = %d\n", omp_get_thread_num());
    printf("i = %d\n", i);
    printf("x = %d\n", x);
    printf("y = %d\n", y);
  }

  printf("The value of y after the parallel black is %d\n", y);

  printf("\ni\ta[i]\t+x\t=\tc[i]\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t%d\t%d\t=\t%d\n", i, a[i], x, b[i]);
  }
}