#include <stdio.h>
#include <stdlib.h>

// 🔹 Fonction de recherche binaire
int rechercheBinaire(int tab[], int n, int x, int *comparaisons) {  // ✅ AJOUT : paramètre comparaisons
    int debut = 0;
    int fin = n - 1;
    int milieu;

    while (debut <= fin) {
        milieu = (debut + fin) / 2;

        (*comparaisons)++;  // ✅ AJOUT : incrémenter à chaque comparaison
        if (tab[milieu] == x)
            return milieu; //  Valeur trouvée
        else if (tab[milieu] < x)
            debut = milieu + 1; //  Chercher à droite
        else
            fin = milieu - 1; //  Chercher à gauche
    }

    return -1; //  Valeur non trouvée
}

int main() {
    FILE *fichier;
    int n, x, i, pos;
    int  choix;
    char nomFichier[50];
    int comparaisons = 0;  // ✅ AJOUT : compteur de comparaisons

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

        default:
            printf(" Choix invalide.\n");
            return 1;
    }


    // 🔹 Ouvrir le fichier contenant le tableau
    fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
          printf(" Erreur : impossible d'ouvrir le fichier %s\n", nomFichier);
        return 1;
    }

    // 🔹 Lire la taille du tableau
    fscanf(fichier, "%d", &n);

    int *tab = (int *)malloc(n * sizeof(int));  // // MODIFICATION ICI tableau dynamique

    // 🔹 Lire les n éléments (doivent être triés pour la recherche binaire)
    for (i = 0; i < n; i++) {
        fscanf(fichier, "%d", &tab[i]);
    }

    fclose(fichier); // fermer le fichier

    // // 🔹 Afficher le tableau lu
    // printf("Tableau lu depuis le fichier (ordre croissant) :\n");
    // for (i = 0; i < n; i++) {
    //     printf("%d ", tab[i]);
    // }
    // printf("\n");

    // 🔹 Saisir la valeur à chercher
    printf("\nEntrez la valeur a rechercher : ");
    scanf("%d", &x);

    // 🔹 Appel de la fonction de recherche binaire
    pos = rechercheBinaire(tab, n, x, &comparaisons);  // ✅ AJOUT : passage du compteur

    // 🔹 Affichage du résultat
    if (pos != -1)
        printf(" La valeur %d est trouvée à la position %d (indice %d).\n", x, pos + 1, pos);
    else
        printf(" La valeur %d n'est pas présente dans le tableau.\n", x);

    printf(" Nombre de comparaisons : %d\n", comparaisons);  // ✅ AJOUT : affichage

    free(tab);  //  LIBÉRATION DE LA MÉMOIRE

    return 0;
}