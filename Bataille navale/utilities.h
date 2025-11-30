#pragma once
#include "grille.h"
#include "ChoixPlacement.h"

bool placement_valide(const grille& g, int x, int y, char orientation, int L);
void placer_bateau(grille& g, int x, int y, int L, char orientation, char symbole);
