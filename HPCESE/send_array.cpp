#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int array []= { 1,2,3,4,5,6,7,8,9,10 };
    int tag = 1;
    int size;
    int rank,i;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0)
    {
         // Array of 10 elements
        if (!array) // error checking
        {
            MPI_Abort(MPI_COMM_WORLD, 1);
        }
        MPI_Send(&array, 10, MPI_INT, 1, tag, MPI_COMM_WORLD);
    }
    if (rank == 1)
    {

        MPI_Recv(&array, 10, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
        printf("Int Array Received from Process 0 to 1 \narray: ");
        i=0;
        for(i=0;i<10;i++)
            printf("%d \t",array[i]);

        // more code here
    }
    MPI_Finalize();
}