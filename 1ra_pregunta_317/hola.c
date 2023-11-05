#include <stdio.h>
#include <omp.h>

int main(void)
{
	#pragma omp parallel num_threads(5)
	{
		int my_rank = omp_get_thread_num();
		int num_threads = omp_get_num_threads();
		printf("Hola Mundo %d of %d.\n", my_rank, num_threads);
	}
	return 0;
}
