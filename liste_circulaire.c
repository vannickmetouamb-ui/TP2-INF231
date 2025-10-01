#include <stdio.h>
#include <stdlib.h>

typedef struct MaillonC {
    int valeur;
    struct MaillonC* suivant;
} MaillonC;

// Insertion en tête
MaillonC* inserer_tete(MaillonC* queue, int val) {
    MaillonC* nouveau = malloc(sizeof(MaillonC));
    if (!nouveau) {
        printf("Erreur d'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }
    nouveau->valeur = val;

    if (queue == NULL) {
        nouveau->suivant = nouveau;
        return nouveau;
    }

    nouveau->suivant = queue->suivant;
    queue->suivant = nouveau;

    return queue;
}

// Insertion en queue
MaillonC* inserer_queue(MaillonC* queue, int val) {
    MaillonC* nouveau = malloc(sizeof(MaillonC));
    if (!nouveau) {
        printf("Erreur d'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }
    nouveau->valeur = val;

    if (queue == NULL) {
        nouveau->suivant = nouveau;
        return nouveau;
    }

    nouveau->suivant = queue->suivant;
    queue->suivant = nouveau;

    return nouveau; // ici on met à jour la queue
}

// Affichage
void afficher(MaillonC* queue) {
    if (queue == NULL) {
        printf("Liste circulaire vide.\n");
        return;
    }

    MaillonC* courant = queue->suivant;
    printf("Liste circulaire : ");
    do {
        printf("%d -> ", courant->valeur);
        courant = courant->suivant;
    } while (courant != queue->suivant);

    printf("(retour)\n");
}

// Libération mémoire
void liberer(MaillonC* queue) {
    if (queue == NULL) return;

    MaillonC* courant = queue->suivant;
    MaillonC* suivant;
    while (courant != queue) {
        suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }
    free(queue);
}

int main() {
    MaillonC* liste = NULL;
    int choix, val;

    do {
        printf("\n1. Insertion en tête\n2. Insertion en queue\n3. Afficher\n0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        if (choix == 1) {
            printf("Valeur : ");
            scanf("%d", &val);
            liste = inserer_tete(liste, val);
        } else if (choix == 2) {
            printf("Valeur : ");
            scanf("%d", &val);
            liste = inserer_queue(liste, val);
        } else if (choix == 3) {
            afficher(liste);
        }
    } while (choix != 0);

    liberer(liste);
    return 0;
}