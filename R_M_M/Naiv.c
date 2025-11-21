#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 🔹 Fonction de recherche du maximum et du minimum (approche naïve)
void MaxEtMinA(int tab[], int n, int *max, int *min, int *nbrComp_max, int *nbrComp_min) {  // ✅ MODIFIÉ : 2 paramètres
    *max = tab[0];
    *min = tab[0];

    for (int i = 1; i < n; i++) {
        (*nbrComp_max)++;  // ✅ MODIFIÉ : compteur pour max
        if (tab[i] > *max)
            *max = tab[i];
        
        (*nbrComp_min)++;  // ✅ MODIFIÉ : compteur pour min
        if (tab[i] < *min)
            *min = tab[i];
    }
}

int main() {
    FILE *fichier;
    int n;
    int  choix;
    char nomFichier[50];
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
    printf(" -11- 2000000_NT.txt\n");
    printf(" -12- 4000000_NT.txt\n");
    printf(" -13- 6000000_NT.txt\n");
    printf(" -14- 8000000_NT.txt\n");
    
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
        case 11:
            sprintf(nomFichier, "../dataset/2000000-nonTrie.txt");
            break;
        case 12:
            sprintf(nomFichier, "../dataset/4000000-nonTrie.txt");
            break;
        case 13:
            sprintf(nomFichier, "../dataset/6000000-nonTrie.txt");
            break;
        case 14:
            sprintf(nomFichier, "../dataset/8000000-nonTrie.txt");
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

    // 🔹 Lire le nombre d'éléments
    fscanf(fichier, "%d", &n);

    int *tab = (int *)malloc(n * sizeof(int));  // MODIFICATION ICI tableau dynamique

    // 🔹 Lire les éléments du tableau
    for (int i = 0; i < n; i++) {
        fscanf(fichier, "%d", &tab[i]);
    }

    fclose(fichier); // 🔹 Fermer le fichier

    // // 🔹 Afficher le tableau lu
    // printf("Tableau lu depuis le fichier :\n");
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", tab[i]);
    // }
    // printf("\n");

    debut = clock();
    // 🔹 Recherche du max et du min
    int max, min, nbrComp_max = 0, nbrComp_min = 0;  // ✅ MODIFIÉ : 2 compteurs séparés
    MaxEtMinA(tab, n, &max, &min, &nbrComp_max, &nbrComp_min);  // ✅ MODIFIÉ : passage des 2 compteurs
    fin = clock();

    // 🔹 Affichage des résultats
    temps_execution = ((double)(fin - debut)) / CLOCKS_PER_SEC;
    printf("\n Le maximum est : %d\n", max);
    printf(" Le minimum est : %d\n", min);
    printf(" Nombre de comparaisons pour trouver le MAX : %d\n", nbrComp_max);  // ✅ AJOUT
    printf(" Nombre de comparaisons pour trouver le MIN : %d\n", nbrComp_min);  // ✅ AJOUT
    printf(" Temps d'execution : %.6f secondes\n", temps_execution);

    free(tab);  //  LIBÉRATION DE LA MÉMOIRE

    return 0;
}