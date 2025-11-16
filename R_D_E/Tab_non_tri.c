#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *fichier;
    int N, X, i, trouve = 0;
    int  choix;
    char nomFichier[50];
    int comparaisons = 0;  // ✅ AJOUT : compteur de comparaisons
    clock_t debut, fin;
    double temps_execution;

    // 🔹 Menu de sélection du fichier
    printf("=== Choisissez le fichier de donnees ===\n");
    printf(" -1- 100000_NT.txt\n");
    printf(" -2- 200000_NT.txt\n");
    printf(" -3- 400000_NT.txt\n");
    printf(" -4- 600000_NT.txt\n");
    printf(" -5- 800000_NT.txt\n");
    printf(" -6- 1000000_NT.txt\n");
    printf(" -7- 1200000_NT.txt\n");
    printf(" -8- 1400000_NT.txt\n");
    printf(" -9- 1600000_NT.txt\n");
    printf(" -10- 1800000_NT.txt\n");
    
    printf("---------------------------------------\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    // 🔹 Déterminer le nom du fichier selon le choix
    switch (choix) {
        case 1:
            sprintf(nomFichier, "../dataset/100000-nonTrie.txt");
            break;
        case 2:
            sprintf(nomFichier, "../dataset/200000-nonTrie.txt");
            break;
        case 3:
            sprintf(nomFichier, "../dataset/400000-nonTrie.txt");
            break;
        case 4:
            sprintf(nomFichier, "../dataset/600000-nonTrie.txt");
            break;
        case 5:
            sprintf(nomFichier, "../dataset/800000-nonTrie.txt");
            break;
        case 6:
            sprintf(nomFichier, "../dataset/1000000-nonTrie.txt");
            break;
        case 7:
            sprintf(nomFichier, "../dataset/1200000-nonTrie.txt");
            break;
        case 8:
            sprintf(nomFichier, "../dataset/1400000-nonTrie.txt");
            break;
        case 9:
            sprintf(nomFichier, "../dataset/1600000-nonTrie.txt");
            break;
        case 10:
            sprintf(nomFichier, "../dataset/1800000-nonTrie.txt");
            break;

        default:
            printf(" Choix invalide.\n");
            return 1;
    }


    // 🔹 Ouvrir le fichier en lecture
    fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf(" Erreur : impossible d'ouvrir le fichier %s\n", nomFichier);
        return 1;
    }

    // 🔹 Lire le nombre d'éléments
    fscanf(fichier, "%d", &N);

    int *tab = (int *)malloc(N * sizeof(int));  // // MODIFICATION ICI tableau dynamique

    // 🔹 Lire les N éléments du fichier
    for (i = 0; i < N; i++) {
        fscanf(fichier, "%d", &tab[i]);
    }

    fclose(fichier); // 🔹 Fermer le fichier après lecture

    // // 🔹 Afficher les éléments du tableau
    // printf("Tableau lu depuis le fichier :\n");
    // for (i = 0; i < N; i++) {
    //     printf("%d ", tab[i]);
    // }
    // printf("\n");

    // 🔹 Lecture de la valeur à chercher
    printf("\nEntrez la valeur a chercher : ");
    scanf("%d", &X);

    debut = clock();
    // 🔹 Recherche linéaire (tableau non trié)
    for (i = 0; i < N; i++) {
        comparaisons++;  // ✅ AJOUT : incrémenter à chaque comparaison
        if (tab[i] == X) {
            printf(" La valeur %d se trouve a la position %d (indice %d)\n", X, i + 1, i);
            trouve = 1;
            break;
        }
    }
    fin = clock();

    // 🔹 Si la valeur n'est pas trouvée
    if (!trouve)
        printf(" La valeur %d n'existe pas dans le tableau.\n", X);

    temps_execution = ((double)(fin - debut)) / CLOCKS_PER_SEC;
    printf(" Nombre de comparaisons : %d\n", comparaisons);  // ✅ AJOUT : affichage
    printf(" Temps d'execution : %.6f secondes\n", temps_execution);

    free(tab);  //  LIBÉRATION DE LA MÉMOIRE

    return 0;
}