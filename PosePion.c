#include "PosePion.h"

void jouer_case_direction (struct Partie *ptPartie,int l,int c,int dl,int dc,int changerPlateau,int *ptChangement)
{
    int i,changements=1,nbChangements=1;

//coup possible dans la direction indiquée ?
    if (coup_possible_direction(*ptPartie,l,c,dl,dc)==1)
    {
        ptPartie->plateau[l+dl][c+dc]=ptPartie->tourJoueur;
        i=2;
    //calcul du nombre de changements
        do
        {
            if (ptPartie->plateau[l+i*dl][c+i*dc]==ptPartie->tourJoueur)//case joueur atteinte : stop
                changements=0;
            else //case adverse atteinte : i++
            {
                nbChangements++;
                i++;
            }
        }while(changements!=0);//tant qu'il y a des changements

    //changements si demandé
        if (changerPlateau==1)
        {
            for (i=0 ; i<nbChangements ; i++)
                ptPartie->plateau[l+i*dl][c+i*dc]=ptPartie->tourJoueur;
        }
    }

    *ptChangement=nbChangements;
    //valeurs changées : *ptPartie et *changement
    //return *ptPartie;
}

void jouer_case(struct Partie *ptPartie,int l,int c,int changerPlateau,int *changementTotal)
{
    int i;
    int direction[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    int changements;

//calcul du nombre de modifications total
    if (changerPlateau==0)
    {
        for (i=0 ; i<8 ; i++)
        {
            jouer_case_direction(ptPartie,l,c,direction[i][0],direction[i][1],0,&changements);
            *changementTotal += changements;
        }
    }
//changement des couleurs dans toutes les direction si demandé
    else
    {
        for (i=0 ; i<8 ; i++)
        {
            jouer_case_direction(ptPartie,l,c,direction[i][0],direction[i][1],1,&changements);
            *changementTotal += changements;
        }
        ptPartie->plateau[l][c]=ptPartie->tourJoueur;
    }

    //valeurs modifiées : *ptPartie et *changementTotal
    //return *ptPartie;
}

void jouer(struct Partie *ptPartie,int *sauvegarde)
{
    int l,c,bonneSaisie;
    char cLettre;
    int pt;//juste pour appeler jouer_case

//Indication du joueur
    switch (ptPartie->tourJoueur)
    {
        case 1 :
            printf("\n\n< ------------- NOIR ------------- >\n\n");
            break;
        case 2 :
            printf("\n\n< ------------- BLANC ------------- >\n\n");
    }

//Saisie des coordonnées
    do
    {
        printf("\n  Saisir la colonne du pion %c placer : ",133);
        scanf("%c",&cLettre);
        while(getchar()!='\n');
        printf("  Saisir la ligne du pion %c placer : ",133);
        scanf("%d",&l);
        while(getchar()!='\n');

    //sauvegarde
        if ((l==0)&&(c='x'))
        {
            bonneSaisie=1;
            *sauvegarde=1;
        }
    //joue
        else
        {
            *sauvegarde=0;
        //décalage des ligne et colonne
            l--;
            c = cLettre-97;
        //vérification du fait que la case est jouable
            if (coup_possible(*ptPartie,l,c)==1)
                bonneSaisie=1;
            else
            {
                bonneSaisie=0;
                printf("  Cette case n'est pas jouable.\n");
            }
        }
    }while (bonneSaisie==0);

//placement des pions
    jouer_case(ptPartie,l,c,1,&pt);

}
