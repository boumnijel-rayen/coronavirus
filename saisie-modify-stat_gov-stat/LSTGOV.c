#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


#include "LSTPRIM.h"
#include "ELTPRIM.h"


NOEUD noeudCreer(ELEMENT e){
NOEUD n;

n = (NOEUD) malloc(sizeof(structNoeud));

if (!n){
printf("probleme d espace\n");
}else{
elementAffecter(&n->info,e);
n->suivant=NULL;
n->precedent=NULL;
}
return n;
}



void noeudDetruire(NOEUD n){
elementDetruire(n->info);
free(n);
}



LISTE listeCreer(){
LISTE l;

l = (LISTE) malloc(sizeof(laStruct));

if (!l){
printf("probleme de memoire\n");
}else{
l->tete=NULL;
l->queue;
l->lg=0;
}
return l;
}




void listeDetruire(LISTE l){
int i;
NOEUD p,q;
q=l->tete;
for (i=1;i<=l->lg;i++){
p=q;
q = q->suivant;
noeudDetruire(p);
}
free(l);
}



int estSaturee(LISTE l){
NOEUD n;
n = (NOEUD) malloc(sizeof(structNoeud));
if (!n){
return 1;
}else{
return 0;
}
}


int estVide(LISTE l){
return (l->lg==0);
}


int listeTaille(LISTE l){
return l->lg;
}




ELEMENT recuperer(LISTE l,int pos){
ELEMENT e = elementCreer();
int i;
NOEUD p;

if (estVide(l)){
printf("liste vide\n");
}else{ if ( (pos < 1) || (pos > l->lg) ){
printf("position invalide\n");
}else{
p=l->tete;
for (i=1;i<pos;i++){
p=p->suivant;
}
elementAffecter(&e,p->info);
}
}
return e;
}


void listeAfficher(LISTE l){
int i;
NOEUD p;

p=l->tete;
for (i=1;i<=l->lg;i++){
elementAfficher(p->info);
p=p->suivant;
}

}



int inserer(LISTE l,ELEMENT e,int pos){
int succes = 1,i;
NOEUD p,q,n;

if (estSaturee(l)){
printf("liste saturee\n");
succes=0;
}else{if ( (pos<1) || (pos>l->lg+1) ){
printf("position invalide \n");
succes=0;
}else{
n = noeudCreer(e);

if (estVide(l)){
l->tete=n;
l->queue=n;
}else{ if (pos ==1){
l->tete->precedent = n;
n->suivant = l->tete;
l->tete =n;
}else{if(pos == l->lg+1){
l->queue->suivant=n;
n->precedent=l->queue;
l->queue=n;
}else{
q=l->tete;
for(i=1;i<pos;i++){
p=q;
q=q->suivant;
}
p->suivant=n;
n->precedent=p;
n->suivant=q;
q->precedent=n;
}

}

}
(l->lg)++;
}

}
return succes;
}



int supprimer(LISTE l,int pos){
int succee=1,i;
NOEUD p,q;

if (estVide(l)){
printf("liste vide\n");
succee=0;
}else{ if ( (pos <1) || (pos > l->lg) ){
printf("position invalide\n");
succee=0;
}else{
if (l->lg == 1){
q=l->tete;
l->tete=NULL;
l->queue=NULL;
}else{if(pos == 1){
q=l->tete;
l->tete=l->tete->suivant;
l->tete->precedent = NULL;
}else{if (pos = l->lg){
q=l->queue;
l->queue = l->queue->precedent;
l->queue->suivant=NULL;
}else{
q=l->tete;
for (i=1;i<pos;i++){
p=q;
q=q->suivant;
}
q->suivant->precedent=p;
p->suivant=q->suivant;
}

}

}
noeudDetruire(q);
(l->lg)--;
}

}
return succee;
}



LISTE listeCopier(LISTE l){
LISTE lc = listeCreer();
int i;
ELEMENT e;

for (i=1;i<=l->lg;i++){
e = elementCreer();
elementCopier(&e,recuperer(l,i));
inserer(lc,e,i);
}
return lc;
}




int listeComparer(LISTE l1,LISTE l2){
int i=1,comp=1;;

if (listeTaille(l1)!=listeTaille(l2)){
comp=0;
}

while ((i<=listeTaille(l1)) && (comp)) {
if
(elementComparer(recuperer(l1,i),recuperer(l2,i))==0)
comp=0;
i++;
}
return comp;
}






