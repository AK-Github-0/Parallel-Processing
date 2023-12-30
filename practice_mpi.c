#include <stdio.h>
#include <string.h> 
#include <mpi.h>    

const int MAX_STRING = 100;

int main(void) 
{
    char greeting[MAX_STRING];
    int comm_sz; 
    int my_rank; 

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    if (my_rank != 0)
    {
        sprintf(greeting, "Hello from process %d of %d!", my_rank, comm_sz);
        MPI_Send(greeting, strlen(greeting) + 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
    } 
    else 
    {
        printf("Hello from process %d of %d!\n", my_rank, comm_sz);
        for (int q = 1; q < comm_sz; q++) 
        {
            MPI_Recv(greeting, MAX_STRING, MPI_CHAR, q, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("%s\n", greeting);
        }
    }

    MPI_Finalize();
    return 0;
}
// this program is an MPI program that involves multiple processes. 
// It uses MPI to send greetings from each process (except process 0) to process 0,
//  which then prints out all the greetings. The output will be a series of greetings
//   from each process, including process 0. The order of the greetings might vary 
//   depending on the execution of the MPI processes.
