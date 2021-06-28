#ifndef ELTGOV_H_INCLUDED
#define ELTGOV_H_INCLUDED


typedef struct{
int j;
int m;
int a;
}DATE;

typedef struct{
DATE date;
char gouv[20];
int casP;
int Deces;
int NbV;
int Guerious;
}gouvernorat,*ELEMENT;

#endif // ELTGOV_H_INCLUDED
