#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "LSTPRIM.h"
#include "ELTPRIM.h"

void saisie(LISTE t[24]);
void lire (LISTE t[24]);
void stat_gouv(LISTE t[24]);
void modifier(LISTE t[24]);
void menu(LISTE t[24]);

int main()
{

    LISTE t[24];
    saisie(t);
    menu(t);
    return 0;
}

void menu(LISTE t[24]){
    int choix;
    printf("---------------------------------------------------------------------------\n");
    printf("               1. Voir les statistiques d'un gouvernourat\n");
    printf("               2. Voir les statistiques\n");
    printf("               3. Modifier\n");
    printf("               4. Supprimer\n");
    printf("               5. Quitter\n");
    printf("---------------------------------------------------------------------------\n");
    scanf("%d",&choix);
    switch (choix){
    case 1:stat_gouv(t);
    break;
    case 2://stat(t);
    break;
    case 3:modifier(t);
    break;
    case 4://supprime(t);
    break;
    case 5:exit(0);
    break;
    }
}


void saisie (LISTE t[24]){
    LISTE l1 = listeCreer();LISTE l2 = listeCreer(); LISTE l3 = listeCreer(); LISTE l4 = listeCreer(); LISTE l5 = listeCreer(); LISTE l6 = listeCreer();
    LISTE l7 = listeCreer(); LISTE l8 = listeCreer(); LISTE l9 = listeCreer(); LISTE l10 = listeCreer(); LISTE l11 = listeCreer(); LISTE l12 = listeCreer();
    LISTE l13 = listeCreer(); LISTE l14 = listeCreer(); LISTE l15 = listeCreer(); LISTE l16 = listeCreer();LISTE l17 = listeCreer();LISTE l18 = listeCreer();
    LISTE l19 = listeCreer(); LISTE l20 = listeCreer(); LISTE l21=listeCreer();LISTE l22 = listeCreer();LISTE l23 = listeCreer();LISTE l24 = listeCreer();
    t[0]=l1;t[1]=l2;t[2]=l3;t[3]=l4;t[4]=l5;t[5]=l6;t[6]=l7;t[7]=l8;t[8]=l9;t[9]=l10;t[10]=l11;t[11]=l12;t[12]=l13;t[13]=l14;t[14]=l15;t[15]=l16;t[16]=l17;t[17]=l18;
    t[18]=l19;t[19]=l20;t[20]=l21;t[21]=l22;t[22]=l23;t[23]=l24;
    lire(t);
}

void lire (LISTE t[24]){
ELEMENT e;

    FILE * f;
    f = fopen("texte.txt","r");

    char ch[50];
    char ch2[50];
    int i,j,r=1,k,mot,pos;

    fgets(ch,50,f);

    while ((!feof(f)) && (r<=20)){
    pos=0;
    while( (pos<24) ) {
    fgets(ch,50,f);
    e=elementCreer();
    mot=0;
    i=0;
    while(i<=strlen(ch)){
        k=0;
    while( (ch[i]!=32)&&(i<=strlen(ch)) ){
    ch2[k] = ch[i];
     i++;
     k++;
    }

    mot++;

    for (j=k;j<k+10;j++){
    ch2[j]='\0';
    }
    if (ch[i] == 32){
    i++;
    }
    switch (mot){
    case 1 : e->date.j= atoi(ch2);
    break;
    case 2 : e->date.m= atoi(ch2);
    break;
    case 3 : e->date.a= atoi(ch2);
    break;
    case 4 : strcpy(e->gouv,ch2);
    break;
    case 5 : e->casP = atoi(ch2);
    break;
    case 6 : e->Guerious = atoi(ch2);
    break;
    case 7 : e->Deces = atoi(ch2);
    break;
    case 8 : e->NbV = atoi(ch2);
    break;
    }
    }
    inserer(t[pos],e,r);
    pos++;
    }
    r++;
    }
    fclose(f);
}







void stat_gouv(LISTE t[24]){
char gouv[50];
int test=1;
int i=0;

printf("Quel gouvernourat allez-vous afficher ?(La premier lettre doit etre majuscule !)\n");
scanf("%s",&gouv);

do{
if (strcmp(recuperer(t[i],1)->gouv,gouv)==0){
test=0;
}else{
i++;
}
}while((test)&&(i<24));

if (test){
printf("la gouvernorat saisee n existe pas\n");
}else{
listeAfficher(t[i]);
}
menu(t);
}



int datecmp (DATE d1,DATE d2){
if ( (d1.j == d2.j) && (d1.m == d2.m) && (d1.a == d2.a) ){
return 1;
}else{
return 0;
}

}




void modifier(LISTE t[24]){
char gouv[20];
DATE da;
int i=0,test=1,j;
NOEUD p;
int cp,d,g,nbv;

printf("Quel gouvernorat alleez-vous modifier ?\n");
scanf("%s",&gouv);


do{
if (strcmp(recuperer(t[i],1)->gouv,gouv)==0){
test=0;
}else{
i++;
}
}while((test)&&(i<24));

if (test){
printf("la gouvernorat saisee n existe pas\n");
}else{
p = t[i]->tete;
j=1;
test=1;
printf("A quel date ?\n");
scanf("%d %d %d",&da.j,&da.m,&da.a);
while ( (test) && (j<=t[i]->lg) ){
if (datecmp(p->info->date,da)==1){
test=0;
}else{
p = p->suivant;
j++;
}
}
if (test){
printf("la date saisee n existe pas\n");
}else{
printf("donner le nouveau nombre des cas positives\n");
scanf("%d",&cp);
printf("donner le nouveau nombre des deces\n");
scanf("%d",&d);
printf("donner le nouveau nombre des Guerious\n");
scanf("%d",&g);
printf("donner le nouveau nombre des vaccines\n");
scanf("%d",&nbv);
p->info->casP=cp;
p->info->Deces=d;
p->info->NbV=nbv;
p->info->Guerious=g;
}

}

menu(t);
}











