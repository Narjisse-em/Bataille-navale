#include "utilities.h"

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

Tir lire_tir_joueur() {
	Tir tir;
	cout << "Entrez une position de tir (x y) entre 0 et 9 : ";
	cin >> tir.x >> tir.y;

	while (tir.x < 0 || tir.x > 9 || tir.y < 0 || tir.y > 9) {
		cout << "Coordonnees invalides ! Reessayez (x y) : ";
		cin >> tir.x >> tir.y;
	}

	return tir;
}


ResultatTir evaluer_tir(grille& g, int x, int y) {

	char& c = g[y][x];

	if (c == '~') {            // vide
		c = 'O';               // tir dans l'eau
		//cout << "A L EAU" << endl;
		return ResultatTir::A_L_EAU;
	}
	else if (c == 'O' || c == 'X') {
		// déjà tiré -> pas d'effet
		return ResultatTir::A_L_EAU;
	}
	else {
		// On a une lettre de bateau
		c = 'X';

		// Vérifier si le bateau est coulé
		// → vérifier si une case du même type existe encore
		char bateau = c;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (g[i][j] == bateau)
					//cout << "TOUCHE" << endl;
					return ResultatTir::TOUCHE;
			}
		}
		//cout << "COULE" << endl;
		return ResultatTir::COULE;
	}
}

//ordinateur adverse qui tire au hasard mais ne doit pas tirer 2 fois au même endroit!
Tir tir_ordi(const grille& vue) {
	Tir t;
	do {
		t.x = rand() % 10;
		t.y = rand() % 10;
	} while (vue[t.y][t.x] == 'O' || vue[t.y][t.x] == 'X');

	return t;
}

