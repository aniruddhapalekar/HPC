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
    a[i] = i + 1;
  }
  int x = 8;
#pragma omp parallel for shared(a, b)
  for (int i = 0; i < n; i++)
  {
    b[i] = a[i] + x;
    printf("thread = %d\n", omp_get_thread_num());
    printf("i = %d\n", i);
  }

  printf("\ni\ta[i]\t+x\t=\tb[i]\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t%d\t%d\t=\t%d\n", i, a[i], x, b[i]);
  }
}