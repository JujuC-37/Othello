#include "Ordinateur.h"

struct Partie jouer_ordi_alea(struct Partie *ptPartie,int couleurOrdi)
{
    srand(time(NULL));
    int i,j,k,t=0,caseTiree,nbCasesLibres;
    int **tab;
    int pt;//juste pour appeler jouer_case

//allocation de mémoire pour le tableau dynamique
    nbCasesLibres = 64 - ptPartie->nbPions[0] - ptPartie->nbPions[1];
    tab=malloc(nbCasesLibres*sizeof(int*));

    for (k=0 ; k<nbCasesLibres ; k++)
        tab[k]=malloc(2*sizeof(int));

//recherche des cases jouables
    for (i=0 ; i<8 ; i++)
    {
        for (j=0 ; j<8 ; j++)
        {
            if (coup_possible(*ptPartie,i,j)==1)
            {
                tab[t][0]=i;
                tab[t][1]=j;
                t++;
            }

        }
    }

//tirage aléatoire

    caseTiree=rand()%t;

//jeu
    jouer_case(ptPartie,tab[caseTiree][0],tab[caseTiree][1],1,&pt);

    return (*ptPartie);

}

struct Partie jouer_ordi_glouton(struct Partie *ptPartie,int couleurOrdi)
{
    int nbCasesLibres,k,t=0,l,c,changement,max,caseMax;
    int **tab;
    int pt;//juste pour appeler jouer_case

//allocation de mémoire pour le tableau dynamique
    nbCasesLibres = 64 - ptPartie->nbPions[0] - ptPartie->nbPions[1];
    tab = malloc(nbCasesLibres*sizeof(int*));

    for (k=0 ; k<nbCasesLibres ; k++)
        tab[k] = malloc(3*sizeof(int));

//recherche des cases jouables et du nombre de pions retournés
    for (l=0 ; l<8 ; l++)
    {
        for (c=0 ; c<8 ; c++)
        {
            if (coup_possible(*ptPartie,l,c)==1)
            {
                jouer_case(ptPartie,l,c,0,&changement);
                tab[t][0]=l;
                tab[t][1]=c;
                tab[t][2]=changement;
                printf("case %d,%d ; changements : %d\n",tab[t][0],tab[t][1],tab[t][2]);
                t++;
            }
        }
    }

//recherche du max
    max=tab[0][2];
    caseMax=0;
    for (k=1 ; k<t ; k++)
    {
        if (tab[k][2]>max)
        {
            max=tab[k][2];
            caseMax=k;
        }
    }
    printf("case : %d,%d ; changements : %d",tab[caseMax][0],tab[caseMax][1],max);
//jeu
    jouer_case(ptPartie,tab[caseMax][0],tab[caseMax][1],1,&pt);
    return(*ptPartie);
}
