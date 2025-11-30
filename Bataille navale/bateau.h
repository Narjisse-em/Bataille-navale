#pragma once
#include "grille.h"

class bateau {
protected:
	int longueur;
	char symbole;

public:
	bateau(int L, char S) :longueur(L), symbole(S) {};
	void placement(grille& g);

	//on va chercher la longueur et le symbole propre à chaque type de bateau
	int getL() { return longueur; };
	char getSymbole() { return symbole; };
};