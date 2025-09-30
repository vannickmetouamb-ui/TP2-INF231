#include "fonctions.h"

int main() {
    Noeud *tete_liste;
    int choix, valeur;

    // Creation de la liste initiale de 4 elements (10, 20, 30, 40)
    tete_liste = creer_liste_initiale();

    printf("--- GESTION DE LISTE DOUBLEMENT CHAINEE CIRCULAIRE ---\n");
    printf("Liste initiale generee (10, 20, 30, 40) :\n");
    afficher_liste(tete_liste);
    printf("------------------------------------------------------\n");

    while (1) {
        printf("\nMenu d'insertion:\n");
        printf("1. Insertion d'un element en Tete\n");
        printf("2. Insertion d'un element en Queue\n");
        printf("3. Afficher la liste actuelle\n");
        printf("0. Quitter le programme\n");
        printf("Votre choix : ");
        if (scanf("%d", &choix) != 1) {
            // Pour gerer les entrees non numeriques
            while(getchar() != '\n'); 
            choix = -1;
        }

        if (choix == 0) {
            break;
        }

        switch (choix) {
            case 1:
                printf("Entrez la valeur entiere a inserer en tete : ");
                scanf("%d", &valeur);
                tete_liste = insertion_tete(tete_liste, valeur);
                printf("Element %d insere en tete.\n", valeur);
                break;
            case 2:
                printf("Entrez la valeur entiere a inserer en queue : ");
                scanf("%d", &valeur);
                tete_liste = insertion_queue(tete_liste, valeur);
                printf("Element %d insere en queue.\n", valeur);
                break;
            case 3:
                afficher_liste(tete_liste);
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    }

    printf("Fin du programme. Au revoir!\n");
    return 0;
}
