#ifndef SAUVEGARDE_H_INCLUDED
#define SAUVEGARDE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Structure.h"
void sauvegarde_fichier(struct Partie unePartie,char typeJeu);
struct Partie initialise_fichier(struct Partie *ptPartie,FILE *svg);

#endif // SAUVEGARDE_H_INCLUDED
