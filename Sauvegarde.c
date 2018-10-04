#include "Sauvegarde.h"

void sauvegarde_fichier(struct Partie unePartie,char typeJeu)
{
    FILE *fichierSvg;
    int i,j;

    if (typeJeu=='d')
    {
        fichierSvg=fopen("sauvegarde2.txt","w");
        if (fichierSvg!=NULL)
        {
            fprintf(fichierSvg,"%d",unePartie.tourJoueur);
            fputc(10,fichierSvg);
            for (i=0 ; i<8 ; i++)
            {
                for (j=0 ; j<8 ; j++)
                {
                    fprintf(fichierSvg,"%d",unePartie.plateau[i][j]);
                    fputc(32,fichierSvg);
                }
                fputc(10,fichierSvg);
            }
        }
        else
            printf("Erreur de sauvegarde");
        fclose(fichierSvg);
    }

    else
    {
        if (typeJeu=='a')
        {
            fichierSvg=fopen("sauvegarde1a.txt","w");
            if (fichierSvg!=NULL)
            {
                fprintf(fichierSvg,"%d",unePartie.tourJoueur);
                fputc(10,fichierSvg);
                for (i=0 ; i<8 ; i++)
                {
                    for (j=0 ; j<8 ; j++)
                        fprintf(fichierSvg,"%d",unePartie.plateau[i][j]);
                    fputc(10,fichierSvg);
                }
            }
            else
                printf("Erreur de sauvegarde");
            fclose(fichierSvg);
        }
        else //typeJeu=='g'
        {
            fichierSvg=fopen("sauvegarde1g.txt","w");
            if (fichierSvg!=NULL)
            {
                fprintf(fichierSvg,"%d",unePartie.tourJoueur);
                fputc(10,fichierSvg);
                for (i=0 ; i<8 ; i++)
                {
                    for (j=0 ; j<8 ; j++)
                        fprintf(fichierSvg,"%d",unePartie.plateau[i][j]);
                    fputc(10,fichierSvg);
                }
                printf("Partie enregistr%ce !",130);
            }
            else
                printf("Erreur de sauvegarde");
            fclose(fichierSvg);
        }
    }
}


struct Partie initialise_fichier(struct Partie *ptPartie,FILE *svg)
{
    int i,j;

    fscanf(svg,"%d",&(ptPartie->tourJoueur));

    for (i=0 ; i<8 ; i++)
    {
        for (j=0 ; j<8 ; j++)
            fscanf(svg,"%d",&(ptPartie->plateau[i][j]));
    }
    return (*ptPartie);
}
