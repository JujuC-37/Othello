#ifndef ORDINATEUR_H_INCLUDED
#define ORDINATEUR_H_INCLUDED

#include <stdlib.h>
#include <time.h>
#include "PionPossible.h"
#include "PosePion.h"
struct Partie jouer_ordi_alea(struct Partie *ptPartie,int couleurOrdi);
struct Partie jouer_ordi_glouton(struct Partie *ptPartie,int couleurOrdi);

#endif // ORDINATEUR_H_INCLUDED
