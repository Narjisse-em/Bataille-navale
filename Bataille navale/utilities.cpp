#include "grille.h"
#include "bateau.h"
#include <vector>

bool placement_valide(const grille& g, int x, int y, char orientation, bateau& b)
{
	//normalisation de l'orientation
	orientation = toupper(orientation);
	int L = b.getL();

	//on verifie que le bateau rentre dans la grille
	if (orientation == 'H') {
		if (x < 0 || y < 0 || x + L >= 10 || y >= 10) return false;
	}//le bateau ne rentre pas

	else if (orientation == 'V') {
		if (x < 0 || y < 0 || x >= 10 || y + L >= 10) return false;
	}//le bateau ne rentre pas

	else
		return false;//orientation incorrecte


	//on verifie que les cases sont libres

	if (orientation == 'H') {
		for (int i = 0; i < L; i++) {
			if (g[y][x + i] != '~') return false; //case occupée
		}

	}
	else if (orientation == 'V') {
		for (int i = 0; i < L; i++) {
			if (g[y + i][x] != '~') return false; //case occupée
		}
	}

	//si aucune erreur, le placement est valide
	return true; //placement valide
}