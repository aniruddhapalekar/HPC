#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{

  int *a;
  int *b;
  int *c;

  int n = 8;
  int i;

  a = (int *)malloc(sizeof(int) * n);
  b = (int *)malloc(sizeof(int) * n);
  c = (int *)malloc(sizeof(int) * n);

  for (i = 0; i < n; i++)
  {
    a[i] = i+1;
  }
  for (i = 0; i < n; i++)
  {
    b[i] = i+1;
  }

#pragma omp parallel for shared(a, b, c) private(i)
  for (i = 0; i < n; i++)
  {
    c[i] = a[i] + b[i];
    printf("Thread Number = %d\n", omp_get_thread_num());
    printf("i = %d\n", i);
  }

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