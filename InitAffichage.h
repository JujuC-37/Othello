#ifndef INITAFFICHAGE_H_INCLUDED
#define INITAFFICHAGE_H_INCLUDED

#include "Structure.h"
struct Partie initialise(struct Partie *ptPartie);
void affiche_plateau(struct Partie unePartie);
void affiche_nombre_pions(struct Partie *ptPartie);
void effacer_console (void);
void affiche(struct Partie unePartie);

#endif // INITAFFICHAGE_H_INCLUDED
