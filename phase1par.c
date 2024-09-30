#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int main() {
    long num_iterations = 1000000;  // Nombre d'itérations
    long points_in_circle = 0;

    // Mesurer le temps de début
    double start_time = omp_get_wtime();

    // Générateur de nombres aléatoires basé sur le thread pour éviter des duplications
    #pragma omp parallel for reduction(+:points_in_circle)
    for (long i = 0; i < num_iterations; i++) {
        // Génération de deux nombres aléatoires entre -1 et 1
        double x = (double)rand() / RAND_MAX * 2.0 - 1.0;
        double y = (double)rand() / RAND_MAX * 2.0 - 1.0;
        
        // Vérifier si le point (x, y) est dans le cercle de rayon 1
        if (x*x + y*y <= 1.0) {
            points_in_circle++;
        }
    }

    // Mesurer le temps de fin
    double end_time = omp_get_wtime();

    // Estimation de pi
    double pi_estimate = 4.0 * (double)points_in_circle / (double)num_iterations;

    // Afficher l'estimation de pi et le temps d'exécution
    printf("Estimation de Pi (parallélisé) : %f\n", pi_estimate);
    printf("Temps d'exécution : %f secondes\n", end_time - start_time);

    return 0;
}
