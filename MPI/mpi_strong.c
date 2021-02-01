#include "mpi.h"
#include <stdio.h>

void calcularStrong(int sn, int en)
{
    int i, n, n1, s1=0,j,k;
    long fact;

 for(k=sn;k<=en;k++)
   {
     n1=k;
     s1=0;

    for(j=k;j>0;j=j/10)
    {

        fact = 1;
          for(i=1; i<=j % 10; i++)
           {
            fact = fact * i;
           }
            s1 = s1 + fact;
    }

    if(s1==n1)

        printf("%d  ", n1);
  }
}

int main(int argc, char** argv){
	double start, end;
	int k;
	int stno,enno;
	int cantidadCiclos[]={0,0,0,0};
	int idTarea, numeroTareas; //variables a usar mpi
	MPI_Init(&argc, &argv); //inicializo mpi
	MPI_Comm_size(MPI_COMM_WORLD, &numeroTareas);
	MPI_Comm_rank(MPI_COMM_WORLD, &idTarea);

	//Tiempo de inicio
	MPI_Barrier(MPI_COMM_WORLD);
	start = MPI_Wtime();

	if(idTarea == 0){
		printf("Input ending number of range : ");
		scanf("%d",&enno);
		printf("Strong numbers in given range are: ");

		for (k = 0; k < numeroTareas; ++k){
			if((k+1)== numeroTareas){ //ultimo
				cantidadCiclos[k]=enno;
			}else{
				cantidadCiclos[k]=enno/numeroTareas;
			}
		}

		calcularStrong(1,cantidadCiclos[0]);
		for (k = 1; k < numeroTareas; ++k){
			MPI_Send(&cantidadCiclos,4,MPI_INT,k,0,MPI_COMM_WORLD); //envia a cada proceso
		}
	}else{
		MPI_Recv(&cantidadCiclos,4,MPI_INT,0,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		calcularStrong(cantidadCiclos[idTarea-1]+1,cantidadCiclos[idTarea]);
	}

	//Tiempo final
	MPI_Barrier(MPI_COMM_WORLD);
	end = MPI_Wtime();
	if(idTarea == 0){
		printf("Tiempo de ejecución = %f\n",end-start);
	}
	printf("\n");
}