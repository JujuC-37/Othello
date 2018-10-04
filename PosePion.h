#ifndef POSEPION_H_INCLUDED
#define POSEPION_H_INCLUDED

#include <stdio.h>
#include "PionPossible.h"
void jouer_case_direction (struct Partie *ptPartie,int l,int c,int dl,int dc,int changerPlateau,int *changement);
void jouer_case(struct Partie *ptPartie,int l,int c,int changerPlateau,int *changementTotal);
void jouer(struct Partie *ptPartie,int *sauvegarde);

#endif // POSEPION_H_INCLUDED
