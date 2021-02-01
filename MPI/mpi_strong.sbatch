#!/bin/bash


#SBATCH --partition=normal
#SBATCH --job-name=mpi_strong # Nombre de la tarea a ejecutar
#SBATCH --nodes=2         # Nodos a usar
#SBATCH --ntasks=2          # Tareas a ejecutar
#SBATCH --cpus-per-task=4
#SBATCH --output=output_mpi_strong.txt

module load devtools/mpi/openmpi/3.1.4    # Modulo que contiene el software a usar

mpirun -np 2 mpi_strong<<< 10000 # "10000" Cantidad de repeticiones
