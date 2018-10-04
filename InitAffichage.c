#include <stdio.h>
#include <stdlib.h>
#include "InitAffichage.h"

struct Partie initialise(struct Partie *ptPartie)
{
    int i,j;

//champ plateau
    for (i=0 ; i<8 ; i++)
    {
        for (j=0 ; j<8 ; j++)
        {
            ptPartie->plateau[i][j] = 0; //cases vides
        }
    }
    ptPartie->plateau[3][4] = 1; //cases noir
    ptPartie->plateau[4][3] = 1;
    ptPartie->plateau[3][3] = 2; //cases blanc
    ptPartie->plateau[4][4] = 2;

//champ joueur
    ptPartie->tourJoueur = 1; //le noir commence

//champ nbPions
    ptPartie->nbPions[0] = 0;
    ptPartie->nbPions[1] = 0;

    return(*ptPartie);
}

void affiche_plateau(struct Partie unePartie)
{
    int i,j,l=1;
    char c=97;

//ligne lettres : i=0
    printf("    ");
    for (j=0 ; j<33 ; j++)
    {
        if ((j+2)%4==0)
        {
            printf("    %c   ",c);
            c++;
        }
    }

//sauts de ligne (fin i=0 et i=1)
    printf ("\n\n");

//plateau (i = {2...33})
    for (i=2 ; i<34 ; i++)
    {
        printf("    ");
        switch(i%4)
        {
            case 2 : //lignes des *
                for (j=0 ; j<33 ; j++)
                    printf("* ");
                printf("\n");
                break;

            case 3 : //lignes "espace"
                for (j=0 ; j<33 ; j+=4)
                    printf("*       ");
                printf("\n");
                break;

            case 1 : //lignes "espace"
                for (j=0 ; j<33 ; j+=4)
                    printf("*       ");
                printf("\n");
                break;

            case 0 : //ligne des pions et numéros de lignes
                for (j=0 ; j<32 ; j++)
                {
                    switch (j%4)
                    {
                        case 0 : //colonnes des *
                            printf("* ");
                            break;

                        case 1 : //colonnes "espace"
                            printf("  ");
                            break;

                        case 3 :  //colonnes "espace"
                            printf("  ");
                            break;

                        case 2 : //colonne des pions
                            switch(unePartie.plateau[(i-2)/4][j/4])
                            {
                                case 0 : //cases vides
                                    printf("  ");
                                    break;

                                case 1 : //cases noires
                                    printf("N ");
                                    break;

                                case 2 : //cases blanches
                                    printf("B ");
                                    break;
                            }
                            break;
                    }
                }
                printf("* %d\n",l); //numéros des lignes
                l++;
                break;
        }
    }

//dernière ligne (i=34)
    printf("    ");
    for (j=0 ; j<33 ; j++)
        printf("* ");
    printf("\n\n");
}

void affiche_nombre_pions(struct Partie *ptPartie)
{
    int i,j;

//on réinitialise les compteurs
    ptPartie->nbPions[0]=0;
    ptPartie->nbPions[1]=0;

//on compte
    for (i=0 ; i<8 ; i++)
    {
        for (j=0 ; j<8 ; j++)
        {
            switch(ptPartie->plateau[i][j])
            {
                case 1 :
                    ptPartie->nbPions[0]++;
                    break;
                case 2 :
                    ptPartie->nbPions[1]++;
                    break;
            }
        }
    }

//on affiche
    printf("\tNombre de pions noirs : %d\n",ptPartie->nbPions[0]);
    printf("\tNombre de pions blancs : %d\n\n",ptPartie->nbPions[1]);
}

void effacer_console (void)
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void affiche(struct Partie unePartie)
{
    effacer_console();
    printf("\n                                    OTHELLO\n");
    affiche_plateau(unePartie);
    affiche_nombre_pions(&unePartie);
}
