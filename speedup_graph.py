import matplotlib.pyplot as plt

# Données
iterations = [10000000, 20000000, 50000000, 100000000]
speedup_1_thread = [4.1]  # Version non optimisée avec 1 thread
speedup_4_threads = [0.155, 1.090, 2.270, 2.442]  # Version optimisée

# Calcul du speedup pour la version optimisée avec 4 threads
speedup_optimized = []
for i in range(len(iterations)):
    seq_time = [0.082, 1.107, 5.764, 11.558][i]  # Temps d'exécution séquentiel
    par_time = [0.530, 1.016, 2.536, 4.737][i]  # Temps d'exécution parallèle
    speedup_optimized.append(seq_time / par_time)

# Tracer le graphique
plt.figure(figsize=(10, 6))
plt.plot(iterations, speedup_optimized, marker='o', label='Optimisé (4 threads)', color='b')
plt.axhline(y=speedup_1_thread[0], color='r', linestyle='--', label='Non optimisé (1 thread)')

# Ajouter des étiquettes et un titre
plt.title('Speedup en fonction du nombre d\'itérations')
plt.xlabel('Nombre d\'itérations')
plt.ylabel('Speedup')
plt.xscale('log')  # Échelle logarithmique pour l'axe x
plt.xticks(iterations)
plt.legend()
plt.grid(True)
plt.show()
