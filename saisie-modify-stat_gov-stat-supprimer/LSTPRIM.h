#ifndef LSTPRIM_H_INCLUDED
#define LSTPRIM_H_INCLUDED

#include "LSTSDD.h"

NOEUD noeudCreer(ELEMENT);
void noeudDetruire(NOEUD);
LISTE listeCreer(void);
void listeDetruire(LISTE);
int estVide(LISTE);
int estSaturee(LISTE);
int listeTaille(LISTE);
ELEMENT recuperer(LISTE, int);
int inserer(LISTE, ELEMENT,int);
int supprimer(LISTE, int);
void listeAfficher(LISTE);
LISTE listeCopier(LISTE);
int listeComparer(LISTE, LISTE);

#endif // LSTPRIM_H_INCLUDED

