#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud Noeud;
struct Noeud {
    int data;
    Noeud *suiv;
    Noeud *prec;
};

Noeud *creer_noeud(int val);
Noeud *creer_liste_initiale();
Noeud *insertion_tete(Noeud *tete, int val);
Noeud *insertion_queue(Noeud *tete, int val);
void afficher_liste(Noeud *tete);
