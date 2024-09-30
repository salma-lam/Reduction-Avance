#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>  // Inclure la bibliothèque pour le temps

int main() {
    long num_iterations = 1000000;  // Nombre d'itérations
    long points_in_circle = 0;
    
    // Mesurer le temps de début
    clock_t start_time = clock();

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
    clock_t end_time = clock();

    // Estimation de pi
    double pi_estimate = 4.0 * (double)points_in_circle / (double)num_iterations;

    // Afficher l'estimation de pi et le temps d'exécution
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Estimation de Pi : %f\n", pi_estimate);
    printf("Temps d'exécution : %f secondes\n", execution_time);

    return 0;
}
