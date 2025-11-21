#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 🔹 Fonction pour trouver le max et le min selon la méthode "par paire"
void MaxEtMinB(int tab[], int n, int *max, int *min, int *comparaisons_max, int *comparaisons_min) {  // ✅ AJOUT : 2 paramètres
    int i;

    // Étape 1 : Comparer les éléments par paires
    for (i = 0; i + 1 < n; i += 2) {
        // ❌ PAS DE COMPTEUR ICI (permutation seulement)
        if (tab[i] < tab[i + 1]) {
            // Le plus petit dans la case impaire, le plus grand dans la paire
            int tmp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = tmp;
        }
    }

    // Étape 2 : Chercher le maximum parmi les indices pairs
    *max = tab[0];
    for (i = 2; i < n; i += 2) {
        (*comparaisons_max)++;  // ✅ AJOUT : compter uniquement pour max
        if (tab[i] > *max)
            *max = tab[i];
    }

    // Étape 3 : Chercher le minimum parmi les indices impairs
    if (n > 1)
        *min = tab[1];
    else
        *min = tab[0];

    for (i = 3; i < n; i += 2) {
        (*comparaisons_min)++;  // ✅ AJOUT : compter uniquement pour min
        if (tab[i] < *min)
            *min = tab[i];
    }

    // Étape 4 : Si nombre impair d'éléments, comparer le dernier non traité
    if (n % 2 != 0) {
        int dernier = tab[n - 1];
        
        (*comparaisons_max)++;  // AJOUT : compter pour max
        if (dernier > *max)
            *max = dernier;
        
        (*comparaisons_min)++;  // AJOUT : compter pour min
        if (dernier < *min)
            *min = dernier;
    }
}

int main() {
    FILE *fichier;
    int n, i;
    int  choix;
    char nomFichier[50];
    int comparaisons_max = 0;  //  compteur pour max
    int comparaisons_min = 0;  //  compteur pour min
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
          printf("Erreur : impossible d'ouvrir le fichier %s\n", nomFichier);
        return 1;
    }

    // 🔹 Lire le nombre d'éléments
    fscanf(fichier, "%d", &n);

    int *tab = (int *)malloc(n * sizeof(int));  // // MODIFICATION ICI tableau dynamique

    // 🔹 Lire les éléments du tableau
    for (i = 0; i < n; i++) {
        fscanf(fichier, "%d", &tab[i]);
    }

    fclose(fichier); // fermer le fichier

    // // 🔹 Afficher les valeurs lues
    // printf("Tableau lu depuis le fichier :\n");
    // for (i = 0; i < n; i++) {
    //     printf("%d ", tab[i]);
    // }
    // printf("\n");

    debut = clock();
    // 🔹 Calcul du max et min
    int max, min;
    MaxEtMinB(tab, n, &max, &min, &comparaisons_max, &comparaisons_min);  // ✅ AJOUT : passage des 2 compteurs
    fin = clock();

    // // 🔹 Affichage des résultats
    // printf("\nTableau après réorganisation (pair=grands / impair=petits) :\n");
    // for (i = 0; i < n; i++)
    //     printf("%d ", tab[i]);
    // printf("\n");

    temps_execution = ((double)(fin - debut)) / CLOCKS_PER_SEC;
    printf(" Maximum = %d\n", max);
    printf(" Minimum = %d\n", min);
    printf(" Nombre de comparaisons pour trouver le MAX : %d\n", comparaisons_max);  // ✅ AJOUT
    printf(" Nombre de comparaisons pour trouver le MIN : %d\n", comparaisons_min);  // ✅ AJOUT
    printf(" Temps d'execution : %.6f secondes\n", temps_execution);

    free(tab);  //  LIBÉRATION DE LA MÉMOIRE

    return 0;
}