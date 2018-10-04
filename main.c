#include <stdio.h>
#include <stdlib.h>
#include "Structure.h"
#include "InitAffichage.h"
#include "PionPossible.h"
#include "PosePion.h"
#include "Partie.h"
#include "Sauvegarde.h"
#include "Ordinateur.h"

int main()
{
    struct Partie maPartie;
    int res;

    printf("\n                                    OTHELLO\n");
    do
    {
        printf("Voulez-vous contre l'ordinateur (1) ou %c 2 joueurs (2)",133);
        scanf("%d",&res);
        while(getchar()!='\n');
    }while ( (res!=1)&&(res!=2) );

    if (res==1)
        jeu_ordi(maPartie);
    else
        jeu_deux(maPartie);

    return 0;
}
