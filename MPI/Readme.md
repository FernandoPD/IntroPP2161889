Strong Numbers

Un Strong Number es un número cuya suma del factorial de todos los dígitos es igual al número 'n'. 
Factorial implica cuando encontramos el producto de todos los números debajo de ese número incluyendo ese número y se denota por! (Signo de exclamación)

por ejemplo: 4! = 4x3x2x1 = 24.

Entonces, para encontrar un número ya sea su número fuerte, tenemos que elegir cada dígito del número como si el número fuera 145, 
luego tenemos que elegir 1, 4 y 5 ahora encontraremos el factorial de cada número, es decir, ¡1! = 1, 4! = 24, 5! = 120.

Se subieron los siguietes archivos:

-strong.c

-mpi_strong.c

-mpi_strong.sbatch

-readme.md

-ouput_mpi_strong.txt

Ejecución del programa:

En Guane:

-module load devtools/mpi/openmpi/3.1.4

-mpicc -lm mpi_strong.c -o mpi_strong(Compilar)

-./mpi_strong (Ejecutar)

-sbatch mpi_strong.sbatch (ejecutar sbatch)

-output_strong.txt (ver salida)

