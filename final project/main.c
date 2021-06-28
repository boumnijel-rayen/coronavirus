#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


#include "LSTPRIM.h"
#include "ELTPRIM.h"


void saisie(LISTE t[23]);
void lire (LISTE t[23]);
void stat_gouv(LISTE t[23]);
void modifier(LISTE t[23]);
void trie_alpha(LISTE l,int ordre);
void permuter(ELEMENT e1,ELEMENT e2);
void trie (LISTE l,int i,int ordre);
void stat(LISTE t[23]);
void supprime(LISTE t[23]);
void ajout(LISTE t[23]);
void ajout_data(LISTE t[23]);
void menu(LISTE t[23]);
void textcolor (unsigned short color);

int main()
{

    LISTE t[23];
    saisie(t);
    menu(t);
    return 0;
}

void menu(LISTE t[23]){
    int choix;
    textcolor(9);
    printf("               %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("               %c                       Menu pricipale                          %c\n",186,186);
    printf("               %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,185);
    printf("               %c            1- Voir les statistiques d'un gouvernourat         %c\n",186,186);
    printf("               %c            2- Voir les statistiques                           %c\n",186,186);
    printf("               %c            3- Ajouter une date                                %c\n",186,186);
    printf("               %c            4- Ajouter de le fichier                           %c\n",186,186);
    printf("               %c            5- Modifier                                        %c\n",186,186);
    printf("               %c            6- Supprimer                                       %c\n",186,186);
    printf("               %c            7- Quitter                                         %c\n",186,186);
    printf("               %c                                                               %c\n",186,186);
    printf("               %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
    textcolor(7);
    do{
    printf("Donnez votre choix\n");
    scanf("%d",&choix);
    }while((choix>7) || (choix<1));
    switch (choix){
    case 1:stat_gouv(t);
    break;
    case 2:stat(t);
    break;
    case 3:ajout(t);
    break;
    case 4:ajout_data(t);
    break;
    case 5:modifier(t);
    break;
    case 6:supprime(t);
    break;
    case 7:exit(0);
    break;
    }
}

void textcolor (unsigned short color){
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hcon,color);
}


void saisie (LISTE t[23]){
    LISTE l1 = listeCreer();LISTE l2 = listeCreer(); LISTE l3 = listeCreer(); LISTE l4 = listeCreer(); LISTE l5 = listeCreer(); LISTE l6 = listeCreer();
    LISTE l7 = listeCreer(); LISTE l8 = listeCreer(); LISTE l9 = listeCreer(); LISTE l10 = listeCreer(); LISTE l11 = listeCreer(); LISTE l12 = listeCreer();
    LISTE l13 = listeCreer(); LISTE l14 = listeCreer(); LISTE l15 = listeCreer(); LISTE l16 = listeCreer();LISTE l17 = listeCreer();LISTE l18 = listeCreer();
    LISTE l19 = listeCreer(); LISTE l20 = listeCreer(); LISTE l21=listeCreer();LISTE l22 = listeCreer();LISTE l23 = listeCreer();LISTE l24 = listeCreer();
    t[0]=l1;t[1]=l2;t[2]=l3;t[3]=l4;t[4]=l5;t[5]=l6;t[6]=l7;t[7]=l8;t[8]=l9;t[9]=l10;t[10]=l11;t[11]=l12;t[12]=l13;t[13]=l14;t[14]=l15;t[15]=l16;t[16]=l17;t[17]=l18;
    t[18]=l19;t[19]=l20;t[20]=l21;t[21]=l22;t[22]=l23;t[23]=l24;
    lire(t);
}

void lire (LISTE t[23]){
ELEMENT e;

    FILE * f;
    f = fopen("data.txt","r");

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







void stat_gouv(LISTE t[23]){
char gouv[50];
int test=1;
int i=0,j,trouve;
float scp=0,sg=0,sd=0,sv=0;
float mcp,mg,md,mv;

printf("Quel gouvernorat allez-vous afficher ?(La premier lettre doit etre majuscule !)\n");
scanf("%s",&gouv);

do{
if (strcmp(recuperer(t[i],1)->gouv,gouv)==0){
test=0;
}else{
i++;
}
}while((test)&&(i<24));

if (test){
    textcolor(4);
printf("la gouvernorat saisee n'existe pas\n");
    textcolor(7);
}else{
    for (j=1;j<=listeTaille(t[i]);j++){
    scp = scp + recuperer(t[i],j)->casP;
    sg = sg + recuperer(t[i],j)->Guerious;
    sd = sd + recuperer(t[i],j)->Deces;
    sv = sv + recuperer(t[i],j)->NbV;
    }
    mcp = scp / listeTaille(t[i]);
    mg = sg / listeTaille(t[i]);
    md = sd / listeTaille(t[i]);
    mv = sv / listeTaille(t[i]);

    textcolor(12);
printf("Date         Gouvernorats    Cas positives    Guerisons  Deces  NB Vaccinees\n");
    textcolor(7);
listeAfficher(t[i]);
textcolor(5);
printf("                            %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196);
textcolor(14);
printf("        \t  moyenne =  \t   %.2f      \t %.2f \t %.2f  \t  %.2f\n",mcp,mg,md,mv);
textcolor(7);
}
menu(t);
}



int datecmp (Date d1,Date d2){
if ( (d1.j == d2.j) && (d1.m == d2.m) && (d1.a == d2.a) ){
return 1;
}else{
return 0;
}

}




void modifier(LISTE t[23]){
char gouv[20];
Date da;
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
    textcolor(4);
printf("la gouvernorat saisee n'existe pas\n");
    textcolor(7);
}else{
p = t[i]->tete;
j=1;
test=1;
printf("A quel date ?(jj-mm-aaaa)\n");
scanf("%d-%d-%d",&da.j,&da.m,&da.a);
while ( (test) && (j<=t[i]->lg) ){
if (datecmp(p->info->date,da)==1){
test=0;
}else{
p = p->suivant;
j++;
}
}
if (test){
printf("la date saisee n'existe pas\n");
}else{
printf("donner le nouveau nombre des cas positives\n");
scanf("%d",&cp);
printf("donner le nouveau nombre des Guerious\n");
scanf("%d",&g);
printf("donner le nouveau nombre des deces\n");
scanf("%d",&d);
printf("donner le nouveau nombre des vaccines\n");
scanf("%d",&nbv);
p->info->casP=cp;
p->info->Deces=d;
p->info->NbV=nbv;
p->info->Guerious=g;
textcolor(10);
printf("La modification fait avec succee\n");
textcolor(7);
}

}

menu(t);
}


void stat(LISTE t[23]){
Date ds;
int ordre,i,j,tr,pos,test,k;
int clet[4];
LISTE l = listeCreer();
ELEMENT e;

printf("A quel date ?(jj-mm-aaaa)\n");
scanf("%d-%d-%d",&ds.j,&ds.m,&ds.a);
test=1;
i=0;
do{
    k=1;
do{
   if (datecmp(recuperer(t[i],k)->date,ds)==1){
   test=0;
   }else{
       k++;
   }
}while( (test)&&(k<=listeTaille(t[i])) );
if (test){
i++;
}
}while( (test) && (i<=23) );

if (test){
    textcolor(4);
printf("La date n'existe pas\n");
    textcolor(7);
}else{
do{
printf("Donnez le cle des cas  positifs\n");
scanf("%d",&clet[0]);
}while( (clet[0] < 1) || (clet[0] > 4) );
do{
printf("Donnez le cle des guerisons\n");
scanf("%d",&clet[1]);
}while((clet[1] < 1) || (clet[1] > 4) || (clet[1] == clet[0]));
do{
printf("Donnez le cle des deces\n");
scanf("%d",&clet[2]);
}while((clet[2] < 1) || (clet[2] > 4) || (clet[2] == clet[0]) || (clet[2] == clet[1]));
do{
printf("Donnez le cle des nombre de vaccines\n");
scanf("%d",&clet[3]);
}while((clet[3] < 1) || (clet[3] > 4) || (clet[3] == clet[0]) || (clet[3] == clet[1]) || (clet[3] == clet[2]));
do{
printf("Choisissez un ordre\n");
printf("1. Croissant\n2. Decroissant\n");
scanf("%d",&ordre);
}while( (ordre != 1) && (ordre != 2) );

pos=0;
for (i=0;i<24;i++){
for (j=1;j<=listeTaille(t[i]);j++){
if (datecmp(recuperer(t[i],j)->date,ds)==1){
pos++;
e = elementCreer();
elementCopier(&e,recuperer(t[i],j));
inserer(l,e,pos);
}
}
}

trie_alpha(l,ordre);

i=0;
tr=1;
while((tr)&&(i<4)){
if (clet[i]==4){
    tr=0;
trie(l,i+1,ordre);
}
i++;
}



i=0;
tr=1;
while((tr)&&(i<4)){
if (clet[i]==3){
    tr=0;
trie(l,i+1,ordre);
}
i++;
}

i=0;
tr=1;
while((tr)&&(i<4)){
if (clet[i]==2){
    tr=0;
trie(l,i+1,ordre);
}
i++;
}

i=0;
tr=1;
while((tr)&&(i<4)){
if (clet[i]==1){
    tr=0;
trie(l,i+1,ordre);
}
i++;
}
textcolor(12);
printf("Date         Gouvernorats    Cas positives    Guerisons  Deces  NB Vaccinees\n");
textcolor(7);
listeAfficher(l);
}
menu(t);
}



void trie_alpha(LISTE l,int ordre){
int tr=1,j;

while(tr){
tr=0;
for (j=1;j<listeTaille(l);j++){
if (ordre==1){
    if (strcmp(recuperer(l,j)->gouv,recuperer(l,j+1)->gouv)>0){
    permuter(recuperer(l,j),recuperer(l,j+1));
    tr=1;
    }
}else{
if (strcmp(recuperer(l,j)->gouv,recuperer(l,j+1)->gouv)<0){
    permuter(recuperer(l,j),recuperer(l,j+1));
    tr=1;
    }
}
}
}

}





void trie (LISTE l,int i,int ordre){
    int tr=1;
    int j;

    while(tr){
    tr=0;
    for (j=1;j<listeTaille(l);j++){
    switch(i){
    case 1:if (ordre==1){if (recuperer(l,j)->casP > recuperer(l,j+1)->casP){
    permuter(recuperer(l,j),recuperer(l,j+1));
    tr=1;
    }}else{
    if (recuperer(l,j)->casP < recuperer(l,j+1)->casP){
    permuter(recuperer(l,j),recuperer(l,j+1));
    tr=1;
    }
    }
    break;
    case 2:if (ordre==1){if (recuperer(l,j)->Guerious > recuperer(l,j+1)->Guerious){
    permuter(recuperer(l,j),recuperer(l,j+1));
    tr=1;
    }}else{
    if (recuperer(l,j)->Guerious < recuperer(l,j+1)->Guerious){
    permuter(recuperer(l,j),recuperer(l,j+1));
    tr=1;
    }
    }
    break;
    case 3:if (ordre==1){if (recuperer(l,j)->Deces > recuperer(l,j+1)->Deces){
    permuter(recuperer(l,j),recuperer(l,j+1));
    tr=1;
    }}else{
    if (recuperer(l,j)->Deces < recuperer(l,j+1)->Deces){
    permuter(recuperer(l,j),recuperer(l,j+1));
    tr=1;
    }
    }
    break;
    case 4:if (ordre==1){if (recuperer(l,j)->NbV > recuperer(l,j+1)->NbV){
    permuter(recuperer(l,j),recuperer(l,j+1));
    tr=1;
    }}else{
    if (recuperer(l,j)->NbV < recuperer(l,j+1)->NbV){
    permuter(recuperer(l,j),recuperer(l,j+1));
    tr=1;
    }
    }
    break;
    }

    }

    }

}


void permuter(ELEMENT e1,ELEMENT e2){
ELEMENT aux = elementCreer();

elementCopier(&aux,e1);
elementCopier(&e1,e2);
elementCopier(&e2,aux);
}





void supprime(LISTE t[23]){
char gouv[50];
int i=0,test=1,j,res;
Date ds;

printf("A quel gouvernorat voulez-vous supprimer?(La premier lettre doit etre majuscule !)\n");
scanf("%s",&gouv);

do{
if (strcmp(recuperer(t[i],1)->gouv,gouv)==0){
test=0;
}else{
i++;
}
}while((test)&&(i<24));

if (test){
    textcolor(4);
printf("La gouvernourat n'existe pas\n");
    textcolor(7);
}else{
test=1;
j=1;
printf("A quel date?(jj-mm-aaaa)\n");
scanf("%d-%d-%d",&ds.j,&ds.m,&ds.a);
do{
   if (datecmp(recuperer(t[i],j)->date,ds)==1){
   test=0;
   }else{
       j++;
   }
}while( (test)&&(j<=listeTaille(t[i])) );
if (test){
    textcolor(4);
printf("La date n'existe pas\n");
    textcolor(7);
}else{
res = supprimer(t[i],j);
if (res==1){
    textcolor(10);
printf("La supprission fait avec succee\n");
    textcolor(7);
}
}
}
menu(t);
}


void ajout(LISTE t[23]){
char gouv[50];
int i=0,test=1,j,res;
Date ds;
ELEMENT e=elementCreer();

printf("A quel gouvernorat voulez-vous ajouter ?(La premier lettre doit etre majuscule !)\n");
scanf("%s",&gouv);

do{
if (strcmp(recuperer(t[i],1)->gouv,gouv)==0){
test=0;
}else{
i++;
}
}while((test)&&(i<24));

if (test){
    textcolor(4);
printf("La gouvernourat n'existe pas\n");
    textcolor(7);
}else{
printf("A quel date?(jj-mm-aaaa)\n");
scanf("%d-%d-%d",&ds.j,&ds.m,&ds.a);
test=1; j=1;
do{
   if (datecmp(recuperer(t[i],j)->date,ds)==1){
   test=0;
   }else{
       j++;
   }
}while( (test)&&(j<=listeTaille(t[i])) );
if (!test){
    textcolor(4);
printf("La date existe\n");
    textcolor(7);
}else{
e->date = ds;
strcpy(e->gouv,recuperer(t[i],1)->gouv);
printf("donner le nouveau nombre des cas positives\n");
scanf("%d",&e->casP);
printf("donner le nouveau nombre des Guerious\n");
scanf("%d",&e->Guerious);
printf("donner le nouveau nombre des deces\n");
scanf("%d",&e->Deces);
printf("donner le nouveau nombre des vaccines\n");
scanf("%d",&e->NbV);
res = inserer(t[i],e,listeTaille(t[i])+1);
if(res){
    textcolor(10);
printf("L'ajout fait avec succee\n");
    textcolor(7);
}
}
}

menu(t);
}

void ajout_data(LISTE t[23]){
ELEMENT e;

FILE * f;
f = fopen("ajout_data.txt","r");

char ch[50];
char ch2[50];
int mot,i,k,j,m;

fgets(ch,50,f);

while(!feof(f)){
e = elementCreer();
fgets(ch,50,f);
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
    for (m=0;m<24;m++){
    if (strcmp(recuperer(t[m],1)->gouv,e->gouv)==0){
    inserer(t[m],e,listeTaille(t[m])+1);
    }
    }
}
    textcolor(10);
    printf("L'ajout fait avec succee\n");
    textcolor(7);

menu(t);
}





















