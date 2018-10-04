#include "Partie.h"
#include "Ordinateur.h"

void jeu_deux(struct Partie unePartie)
{
    int i,j,toursPasses=0,choixSvgNv;
    int sauvegarde;
    FILE *svg=NULL;

//test d'existence de partie enregistrée (sauvegarde2.txt) et initialisation
    svg=fopen("sauvegarde2.txt","r");
    if (svg!=NULL)
    {
        printf("Voulez-vous continuer la partie enregistr%ce (1) ou en commencer une nouvelle (0) ?",130);
        scanf("%d",&choixSvgNv);

        if (choixSvgNv==0)
            initialise(&unePartie);
        else
            initialise_fichier(&unePartie,svg);

        if (fclose(svg))
            printf("probl%cme de fermeture du fichier de sauvegarde",138);
    }
    else
        initialise(&unePartie);


//Partie
    do
    {
    //Tour d'un joueur
        affiche(unePartie);
        if (possible(unePartie)==1) //le joueur peut poser un pion
        {
            jouer(&unePartie,&sauvegarde); //renvoie toursPasses et sauvegarde
            toursPasses=0;
        }
        else //le joueur passe son tour
        {
            printf("  Aucune case n'est jouable. Joueur suivant.\n");
            toursPasses++;
            printf("  Voulez-vous sauvegarder la partie (1) ou non (0)");
            scanf("%d",&sauvegarde);
        }

    //Changement de joueur
        if(unePartie.tourJoueur==1)
            unePartie.tourJoueur=2;
        else
            unePartie.tourJoueur=1;

    //Calcul des nombres de pions
        //on réinitialise les compteurs
            unePartie.nbPions[0]=0;
            unePartie.nbPions[1]=0;
        //on compte
            for (i=0 ; i<8 ; i++)
            {
                for (j=0 ; j<8 ; j++)
                {
                    switch(unePartie.plateau[i][j])
                    {
                        case 1 :
                            unePartie.nbPions[0]++;
                            break;
                        case 2 :
                            unePartie.nbPions[1]++;
                            break;
                    }
                }
            }
    }while( (toursPasses<2)||(sauvegarde==1) );

//Partie arrêtée
    if (toursPasses==2)//Partie terminée
    {
        if (unePartie.nbPions[0]==unePartie.nbPions[1])
            printf("  Il y a match nul.\n");
        else
        {
            if(unePartie.nbPions[0]>unePartie.nbPions[1])
                printf("  Le joueur noir a gagn%c !",130);
            else
                printf("  Le joueur blanc a gagn%c !",130);
        }

        if (choixSvgNv==1) //Suppression de la sauvegarde terminée
            remove("sauvegarde2.txt");
    }
    else//partie suspendue et sauvegardée
        sauvegarde_fichier(unePartie,'d');
}

void jeu_ordi(struct Partie unePartie)
{
    int couleurJ,couleurO,mode,toursPasses=0,choixSvgNv,i,j;
    int sauvegarde;
    FILE *svg=NULL;

//choix des couleurs
    do
    {
        printf("Voulez-vous commencer (1) ou laisser l'ordinateur commencer (2) ?");
        scanf("%d",&couleurJ);
        while(getchar()!='\n');
    }while ( (couleurJ!=1)&&(couleurJ!=2) );

    if (couleurJ==1)
        couleurO=2;
    else
        couleurO=1;

//choix du mode
    do
    {
        printf("Voulez-vous que l'ordinateur joue de fa%con al%catoire (1) ou gloutonne (2) ?",135,130);
        scanf("%d",&mode);
        while(getchar()!='\n');
    }while ( (mode!=1)&&(mode!=2) );

//mode aléatoire
    if (mode==1)
    {
    //test d'existence de partie enregistrée (sauvegarde1a.txt) et initialisation
        svg=fopen("sauvegarde1a.txt","r");
        if (svg!=NULL)
        {
            printf("Voulez-vous continuer la partie enregistr%ce (1) ou en commencer une nouvelle (0) ?",130);
            scanf("%d",&choixSvgNv);

            if (choixSvgNv==0)
                initialise(&unePartie);
            else
                initialise_fichier(&unePartie,svg);

            if (fclose(svg))
                printf("probl%cme de fermeture du fichier de sauvegarde",138);
        }
        else
            initialise(&unePartie);

    //Partie
        do
        {
        //Joueur
            if (unePartie.tourJoueur==couleurJ)
            {
                affiche(unePartie);
                if (possible(unePartie)==1) //le joueur peut poser un pion
                {
                    jouer(&unePartie,&sauvegarde); //renvoie toursPasses et sauvegarde
                    toursPasses=0;
                }
                else //le joueur passe son tour
                {
                    printf("  Aucune case n'est jouable. Joueur suivant.\n");
                    toursPasses++;
                    printf("  Voulez-vous sauvegarder la partie (1) ou non (0)");
                    scanf("%d",&sauvegarde);
                }
            }
        //Ordinateur
            else
            {
                if (possible(unePartie)==1) //l'ordinateur peut jouer
                {
                    jouer_ordi_alea(&unePartie,couleurO);
                    toursPasses=0;
                }
                else //l'ordinateur passe son tour
                {
                    toursPasses++;
                }
            }
        //Changement de joueur
            if(unePartie.tourJoueur==1)
                unePartie.tourJoueur=2;
            else
                unePartie.tourJoueur=1;

        //Calcul des nombres de pions
            //on réinitialise les compteurs
                unePartie.nbPions[0]=0;
                unePartie.nbPions[1]=0;
            //on compte
                for (i=0 ; i<8 ; i++)
                {
                    for (j=0 ; j<8 ; j++)
                    {
                        switch(unePartie.plateau[i][j])
                        {
                            case 1 :
                                unePartie.nbPions[0]++;
                                break;
                            case 2 :
                                unePartie.nbPions[1]++;
                                break;
                        }
                    }
                }
        }while( (toursPasses<2)||(sauvegarde==1) );

    //Partie arrêtée
        if (toursPasses==2)//Partie terminée
        {
            if (unePartie.nbPions[0]==unePartie.nbPions[1])
                printf("  Il y a match nul.\n");
            else
            {
                if(unePartie.nbPions[0]>unePartie.nbPions[1])
                {
                    if(couleurJ==1)
                        printf("  Vous avez gagn%c !",130);
                    else
                        printf("  Vous avez perdu...");
                }
                else
                {
                    if(couleurJ==2)
                        printf("  Vous avez gagn%c !",130);
                    else
                        printf("  Vous avez perdu...");
                }
            }

            if (choixSvgNv==1) //Suppression de la partie sauvegardée terminée
                remove("sauvegarde1a.txt");
        }
        else//partie suspensue et sauvegardée
            sauvegarde_fichier(unePartie,'a');
    }

//mode glouton
    else
    {
    //test d'existence de partie enregistrée (sauvegarde1g.txt) et initialisation
        svg=fopen("sauvegarde1g.txt","r");
        if (svg!=NULL)
        {
            printf("Voulez-vous continuer la partie enregistr%ce (1) ou en commencer une nouvelle (0) ?",130);
            scanf("%d",&choixSvgNv);

            if (choixSvgNv==0)
                initialise(&unePartie);
            else
                initialise_fichier(&unePartie,svg);

            if (fclose(svg))
                printf("probl%cme de fermeture du fichier de sauvegarde",138);
        }
        else
            initialise(&unePartie);

    //Partie
        do
        {
        //Joueur
            if (unePartie.tourJoueur==couleurJ)
            {
                affiche(unePartie);
                if (possible(unePartie)==1) //le joueur peut poser un pion
                {
                    jouer(&unePartie,&sauvegarde); //renvoie toursPasses et sauvegarde
                    toursPasses=0;
                }
                else //le joueur passe son tour
                {
                    printf("  Aucune case n'est jouable. Joueur suivant.\n");
                    toursPasses++;
                    printf("  Voulez-vous sauvegarder la partie (1) ou non (0)");
                    scanf("%d",&sauvegarde);
                }
            }
        //Ordinateur
            else
            {
                if (possible(unePartie)==1) //l'ordinateur peut jouer
                {
                    jouer_ordi_glouton(&unePartie,couleurO);
                    toursPasses=0;
                }
                else //l'ordinateur passe son tour
                {
                    toursPasses++;
                }
            }
        //Changement de joueur
            if(unePartie.tourJoueur==1)
                unePartie.tourJoueur=2;
            else
                unePartie.tourJoueur=1;

        //Calcul des nombres de pions
            //on réinitialise les compteurs
                unePartie.nbPions[0]=0;
                unePartie.nbPions[1]=0;
            //on compte
                for (i=0 ; i<8 ; i++)
                {
                    for (j=0 ; j<8 ; j++)
                    {
                        switch(unePartie.plateau[i][j])
                        {
                            case 1 :
                                unePartie.nbPions[0]++;
                                break;
                            case 2 :
                                unePartie.nbPions[1]++;
                                break;
                        }
                    }
                }
        }while( (toursPasses<2)||(sauvegarde==1) );

    //Partie arrêtée
        if (toursPasses==2)//Partie terminée
        {
            if (unePartie.nbPions[0]==unePartie.nbPions[1])
                printf("  Il y a match nul.\n");
            else
            {
                if(unePartie.nbPions[0]>unePartie.nbPions[1])
                {
                    if(couleurJ==1)
                        printf("  Vous avez gagn%c !",130);
                    else
                        printf("  Vous avez perdu...");
                }
                else
                {
                    if(couleurJ==2)
                        printf("  Vous avez gagn%c !",130);
                    else
                        printf("  Vous avez perdu...");
                }
            }

            if (choixSvgNv==1) //Suppression de la partie sauvegardée terminée
                remove("sauvegarde1g.txt");
        }
        else//partie suspensue et sauvegardée
            sauvegarde_fichier(unePartie,'g');
    }
}
