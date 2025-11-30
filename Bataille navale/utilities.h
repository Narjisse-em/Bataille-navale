#pragma once
#include "grille.h"
#include "ChoixPlacement.h"
#include "Tir.h"

bool placement_valide(const grille& g, int x, int y, char orientation, int L);
void placer_bateau(grille& g, int x, int y, int L, char orientation, char symbole);
Tir lire_tir_joueur();
ResultatTir evaluer_tir(grille& g, int x, int y);
Tir tir_ordi(const grille& vue);
