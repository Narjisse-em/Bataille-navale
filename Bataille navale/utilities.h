#include "grille.h"
#include "bateau.h"
#include "ChoixPlacement.h"
#include "porteavion.h"
#include "croiseur.h"
#include "contretorpilleur.h"
#include "sousmarin.h"
#include "torpilleur.h"
#include <vector>

bool placement_valide(const grille& g, int x, int y, char orientation, int L)
{

	//on vérifie les limites du plateau
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



//fonction pour placer le bateau à la main une fois que sa position est valide
void placer_bateau(grille& g, int x, int y, int L, char orientation, char symbole)
{
	orientation = toupper(orientation);

	if (orientation == 'H') {
		for (int i = 0; i < L; i++) {
			g[y][x + i] = symbole;
		}
	}
	else if (orientation == 'V') {
		for (int i = 0; i < L; i++) {
			g[y + i][x] = symbole;
		}
	}
}

