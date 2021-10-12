/*
Analyse and implement a Parallel code for below programs using OpenMP
considering synchronization requirements. (Demonstrate the use of different 
clauses and constructs wherever applicable)
*/

#include <stdio.h>
#include <stdlib.h>

int mutex = 1;
int full = 0;
int empty = 5, x = 0;

void producer()
{
	--mutex;
	++full;
	--empty;
	x++;
	printf("Producer produces " "item %d\n", x);
	++mutex;
}


void consumer()
{
	--mutex;
	--full;
	++empty;
	printf("Consumer consumes " "item %d\n", x);
	x--;
	++mutex;
}


int main()
{
	int n, i;
	printf("\n1) Producer"
	"\n2) Consumer"
	"\n3) Exit\n");

	#pragma omp critical
	for (i = 1; i > 0; i++) 
	{
		printf("\nOption No : ");
		scanf("%d", &n);
		switch (n) 
		{
			case 1:
				if ((mutex == 1)
				&& (empty != 0)) 
				{
					producer();
				}
				else 
				{
					printf("Buffer is full!\n");
				}
				break;
			case 2:
				if ((mutex == 1) && (full != 0)) 
				{
					consumer();
				}
				else 
				{
				printf("Buffer is empty!\n");

				}
				break;
			case 3:
				exit(0);
				break;
		}
	}
}