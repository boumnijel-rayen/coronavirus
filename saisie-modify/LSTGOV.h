#ifndef LSTGOV_H_INCLUDED
#define LSTGOV_H_INCLUDED

#include "ELTPRIM.h"

typedef struct structNoeud {
ELEMENT info;
struct structNoeud * precedent;
struct structNoeud * suivant;
} structNoeud, * NOEUD;



typedef struct {
NOEUD tete;
NOEUD queue;
int lg;
} laStruct,*LISTE;

#endif // LSTGOV_H_INCLUDED
