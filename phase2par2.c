#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <time.h>

void run_parallel(long num_iterations) {
    long points_in_circle = 0;
    clock_t start_time = clock();

    #pragma omp parallel
    {
        long local_count = 0;

        #pragma omp for schedule(dynamic)
        for (long i = 0; i < num_iterations; i++) {
            double x = (double)rand() / RAND_MAX * 2.0 - 1.0;
            double y = (double)rand() / RAND_MAX * 2.0 - 1.0;

            if (x*x + y*y <= 1.0) {
                local_count++;
            }
        }

        #pragma omp atomic
        points_in_circle += local_count;
    }

    double pi_estimate = 4.0 * (double)points_in_circle / (double)num_iterations;
    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Estimation de Pi pour %ld itérations (parallèle) : %f\n", num_iterations, pi_estimate);
    printf("Temps d'exécution : %f secondes\n", execution_time);
}

int main() {
    long iteration_sizes[] = {10000000, 20000000, 50000000, 100000000};

    for (int i = 0; i < sizeof(iteration_sizes) / sizeof(iteration_sizes[0]); i++) {
        run_parallel(iteration_sizes[i]);
    }

    return 0;
}
