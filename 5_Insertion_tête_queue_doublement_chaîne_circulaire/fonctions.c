#include "fonctions.h"

Noeud *creer_noeud(int val) {
    Noeud *nouveau = (Noeud *)malloc(sizeof(Noeud));
    nouveau->data = val;
    nouveau->suiv = nouveau;
    nouveau->prec = nouveau;
    return nouveau;
}

Noeud *creer_liste_initiale() {
    Noeud *tete = NULL;
    int i;
    int elements_initiaux[] = {10, 20, 30, 40};

    for (i = 0; i < 4; i++) {
        tete = insertion_queue(tete, elements_initiaux[i]);
    }
    return tete;
}

Noeud *insertion_tete(Noeud *tete, int val) {
    Noeud *nouveau = creer_noeud(val);
    if (tete == NULL) {
        return nouveau;
    }
    
    Noeud *derniere = tete->prec;
    
    nouveau->suiv = tete;
    nouveau->prec = derniere;
    
    tete->prec = nouveau;
    derniere->suiv = nouveau;
    
    return nouveau; 
}

Noeud *insertion_queue(Noeud *tete, int val) {
    Noeud *nouveau = creer_noeud(val);
    if (tete == NULL) {
        return nouveau;
    }
    
    Noeud *derniere = tete->prec;
    
    nouveau->suiv = tete;
    nouveau->prec = derniere;
    
    tete->prec = nouveau;
    derniere->suiv = nouveau;
    
    return tete; 
}

void afficher_liste(Noeud *tete) {
    if (tete == NULL) {
        printf("La liste est vide.\n");
        return;
    }
    
    Noeud *actuel = tete;
    printf("Liste (tete -> queue -> tete): ");
    
    do {
        printf("[%d] ", actuel->data);
        actuel = actuel->suiv;
    } while (actuel != tete);
    
    printf("\n");
}
