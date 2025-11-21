#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 🔹 Fonction de recherche séquentielle optimisée (pour tableau trié)
int rechercheSequentielle(int tab[], int n, int x, int *comparaisons) {  
    for (int i = 0; i < n; i++) {
        (*comparaisons)++;  //  incrémenter à chaque comparaison
        if (tab[i] == x)
            return i; // Valeur trouvée
        else if (tab[i] > x)
            return -1; //  Inutile de continuer (tableau trié)
    }
    return -1; //  Valeur non trouvée
}

int main() {
    FILE *fichier;
    int  x, i, pos;
    int n, choix;
    char nomFichier[50];
    int comparaisons = 0;  // 
    clock_t debut, fin;
    double temps_execution;

  
     // 🔹 Menu de sélection du fichier
    printf("=== Choisissez le fichier de donnees ===\n");
    printf(" -1- 100000_T.txt\n");
    printf(" -2- 200000_T.txt\n");
    printf(" -3- 400000_T.txt\n");
    printf(" -4- 600000_T.txt\n");
    printf(" -5- 800000_T.txt\n");
    printf(" -6- 1000000_T.txt\n");
    printf(" -7- 1200000_T.txt\n");
    printf(" -8- 1400000_T.txt\n");
    printf(" -9- 1600000_T.txt\n");
    printf(" -10- 1800000_T.txt\n");
    printf(" -11- 2000000_T.txt\n");
    printf(" -12- 4000000_T.txt\n");
    printf(" -13- 6000000_T.txt\n");
    printf(" -14- 8000000_T.txt\n");
    
    printf("---------------------------------------\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    // 🔹 Déterminer le nom du fichier selon le choix
    switch (choix) {
        case 1:
            sprintf(nomFichier, "../dataset/100000-Trie.txt");
            break;
        case 2:
            sprintf(nomFichier, "../dataset/200000-Trie.txt");
            break;
        case 3:
            sprintf(nomFichier, "../dataset/400000-Trie.txt");
            break;
        case 4:
            sprintf(nomFichier, "../dataset/600000-Trie.txt");
            break;
        case 5:
            sprintf(nomFichier, "../dataset/800000-Trie.txt");
            break;
        case 6:
            sprintf(nomFichier, "../dataset/1000000-Trie.txt");
            break;
        case 7:
            sprintf(nomFichier, "../dataset/1200000-Trie.txt");
            break;
        case 8:
            sprintf(nomFichier, "../dataset/1400000-Trie.txt");
            break;
        case 9:
            sprintf(nomFichier, "../dataset/1600000-Trie.txt");
            break;
        case 10:
            sprintf(nomFichier, "../dataset/1800000-Trie.txt");
            break;
        case 11:
            sprintf(nomFichier, "../dataset/2000000-Trie.txt");
            break;
        case 12:
            sprintf(nomFichier, "../dataset/4000000-Trie.txt");
            break;
        case 13:
            sprintf(nomFichier, "../dataset/6000000-Trie.txt");
            break;
        case 14:
            sprintf(nomFichier, "../dataset/8000000-Trie.txt");
            break;

        default:
            printf(" Choix invalide.\n");
            return 1;
    }

    

    // 🔹 Ouvrir le fichier contenant les données
    fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
         printf(" Erreur : impossible d'ouvrir le fichier %s\n", nomFichier);
        return 1;
    }

    // 🔹 Lire la taille du tableau
    fscanf(fichier, "%d", &n);

    int *tab = (int *)malloc(n * sizeof(int));  // // MODIFICATION ICI tableau dynamique

    // 🔹 Lire les éléments du tableau (doivent être triés pour optimisation)
    for (i = 0; i < n; i++) {
        fscanf(fichier, "%d", &tab[i]);
    }

    fclose(fichier); // fermer le fichier

    // // 🔹 Afficher les éléments lus
    // printf("Tableau lu depuis le fichier (ordre croissant) :\n");
    // for (i = 0; i < n; i++) {
    //     printf("%d ", tab[i]);
    // }
    // printf("\n");

    // 🔹 Lecture de la valeur à rechercher
    printf("\nEntrez la valeur a rechercher : ");
    scanf("%d", &x);

    debut = clock();
    // 🔹 Appel de la fonction de recherche séquentielle
    pos = rechercheSequentielle(tab, n, x, &comparaisons); 
    fin = clock();

    // 🔹 Afficher le résultat
    if (pos != -1)
        printf(" La valeur %d est trouvée à la position %d (indice %d).\n", x, pos + 1, pos);
    else
        printf(" La valeur %d n'est pas présente dans le tableau.\n", x);

    temps_execution = ((double)(fin - debut)) / CLOCKS_PER_SEC;
    printf(" Nombre de comparaisons : %d\n", comparaisons);  
    printf(" Temps d'execution : %.6f secondes\n", temps_execution);

    free(tab);  //  LIBÉRATION DE LA MÉMOIRE

    return 0;
}