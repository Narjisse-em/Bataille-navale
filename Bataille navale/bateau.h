#pragma once
#include "grille.h"

class bateau {
protected:
	int longueur;
	char symbole;

public:
	bateau(int L, char S) :longueur(L), symbole(S) {};
	void placement(grille& g);

	int getL() { return longueur; };
};