#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#define ARRAY_SIZE 8

int main()
{

  int *a;
  int *b;
  int *c;

  int n = ARRAY_SIZE;
  int i, x = 33;

  a = (int *)malloc(sizeof(int) * n);
  b = (int *)malloc(sizeof(int) * n);
  c = (int *)malloc(sizeof(int) * n);

  for (i = 0; i < n; i++)
  {
    a[i] = i + 1;
  }
  for (i = 0; i < n; i++)
  {
    b[i] = i + 1;
  }

#pragma omp parallel for firstprivate(x)
  for (i = 0; i < n; i++)
  {
    c[i] = a[i] + b[i];
    printf("Thread = %d\n", omp_get_thread_num());
    printf("i = %d\n", i);
    printf("x = %d\n", x);
    x = i;
    printf("Thread = %d\n", omp_get_thread_num());
    printf("i = %d\n", i);
    printf("x = %d\n", x);
  }

  printf("Value of x after parallel block is %d\n", x);

  printf("i\ta[i]\t+\tb[i]\t=\tc[i]\n");
  for (i = 0; i < n; i++)
  {
    printf("%d\t%d\t\t%d\t\t%d\n", i, a[i], b[i], c[i]);
  }

  free(a);
  free(b);
  free(c);

  return 0;
}