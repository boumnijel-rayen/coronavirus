#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#include "ELTPRIM.h"

ELEMENT elementCreer(){
ELEMENT e;

e = (ELEMENT) malloc(sizeof(gouvernorat));

e->date.j=0;
e->date.m=0;
e->date.a=0;
strcpy(e->gouv,"");
e->casP=0;
e->Deces=0;
e->Guerious=0;
e->NbV=0;

return e;
}

void elementLire(ELEMENT * e){
printf("donner la date\n");
scanf("%d %d %d",&(*e)->date.j,&(*e)->date.m,&(*e)->date.a);
printf("donner le nom de gouvernorat \n");
scanf("%s",&(*e)->gouv);
printf("donner les cas positives \n");
scanf("%d",&(*e)->casP);
printf("donner les deses \n");
scanf("%d",&(*e)->Deces);
printf("donner le nombre des vaccines \n");
scanf("%d",&(*e)->NbV);
printf("donner les guerious \n");
scanf("%d",&(*e)->Guerious);
}



void elementDetruire(ELEMENT e){
free(e);
}

void elementAfficher(ELEMENT e){
printf("%d-%d-%d  \t  %s   \t   %d   \t   %d  \t  %d  \t  %d\n",e->date.j,e->date.m,e->date.a,e->gouv,e->casP,e->Guerious,e->Deces,e->NbV);
}

void elementAffecter(ELEMENT * e1,ELEMENT e2){
*e1 = e2;
}

void elementCopier(ELEMENT * e1,ELEMENT e2){
memcpy(*e1,e2,sizeof(gouvernorat));
}



int elementComparer(ELEMENT e1,ELEMENT e2){

if ( (e1->date.j == e2->date.j) && (e1->date.m == e2->date.m) && (e1->date.a == e2->date.a) && (strcmp(e1->gouv,e2->gouv) == 0) && (e1->casP == e2->casP) && (e1->Deces == e2->Deces) && (e1->NbV == e2->NbV) && (e1->Guerious == e2->Guerious)){
return 1;
}else{
return 0;
}
}



