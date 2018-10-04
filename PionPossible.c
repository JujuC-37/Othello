#include "PionPossible.h"

int coup_possible_direction (struct Partie unePartie,int l,int c,int dl,int dc)
{
    int i,resultat;

//case déjà occupée ?
    if (unePartie.plateau[l][c]!=0)
        resultat=0;

    else
    {
    //déplacement sur le plateau ?
        if ((l+dl<0)||(l+dl>7)||(c+dc<0)||(c+dc>7))
            resultat=0;

        else
        {
        //le déplacement donne une case vide ?
            if (unePartie.plateau[l+dl][c+dc]==0)
                resultat=0;

            else
            {
            //à qui est le pion ?
                if (unePartie.plateau[l+dl][c+dc]==unePartie.tourJoueur) //pion du joueur
                    resultat=0;

                else //pion adverse.
                {
                    i=2;
                //on regarde les pions suivants dans la même direction
                    do
                    {
                    //case vide ?
                        if (unePartie.plateau[l+i*dl][c+i*dc]==0)
                            resultat=0;
                        else
                        {
                        //pion joueur ?
                            if (unePartie.plateau[l+i*dl][c+i*dc]==unePartie.tourJoueur)
                                resultat=1;
                            else //pion adverse après pion(s) adverse(s) : on continue
                            {
                                i++;
                                resultat=-1;
                            }
                        }
                    }while ((resultat==-1) && (l+i*dl>=0)&&(l+i*dl<=7) && (c+i*dc>=0)&&(c+i*dc<=7) );

                }
            }
        }

    }


    if (resultat==-1)
        resultat = 0;

    return resultat;
}

int coup_possible(struct Partie unePartie,int l,int c)
{
    int i=0,resultat=0;
    int direction[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

    while( (resultat==0)&&(i<8) )
    {
        resultat=coup_possible_direction(unePartie,l,c,direction[i][0],direction[i][1]);
        i++;
    }

    return resultat;
}


int possible(struct Partie unePartie)
{
    int i=0,j,resultat=0;

    while ( (resultat==0)&&(i<8) )
    {
        j=0;
        while( (resultat==0)&&(j<8) )
        {
            resultat=coup_possible(unePartie,i,j);
            j++;
        }
        i++;
    }
    return resultat;
}
