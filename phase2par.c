#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <time.h>
int main() {
    long num_iterations = 10000000;  
    long points_in_circle = 0;
    clock_t start_time = clock();

    #pragma omp parallel
    {
        long local_count = 0;  // Variable locale pour chaque thread

        #pragma omp for schedule(dynamic)  // Essayer dynamic ou static
        for (long i = 0; i < num_iterations; i++) {
            double x = (double)rand() / RAND_MAX * 2.0 - 1.0;
            double y = (double)rand() / RAND_MAX * 2.0 - 1.0;
            
            if (x*x + y*y <= 1.0) {
                local_count++;  // Compte local
            }
        }

        #pragma omp atomic
        points_in_circle += local_count;  // Réduction atomique pour éviter les conflits
    }

    clock_t end_time = clock();
    double pi_estimate = 4.0 * (double)points_in_circle / (double)num_iterations;
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Estimation de Pi : %f\n", pi_estimate);
    printf("Temps d'exécution : %f secondes\n", execution_time);

    return 0;
}
