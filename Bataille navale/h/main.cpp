#include<iostream>
#include "grille.h"
#include "bateau.h"
#include "contre-torpilleur.h"
#include "croiseur.h"
#include "porte-avion.h"
#include "sous-marin.h"
#include "torpilleur.h"
#include "jeu.h"

int main() {

	//initialisation des grilles
	//G1 humain tire robot place 
	//G2 robot tire humain place 

	grille G1 = grille();
	grille G2 = grille();

	bool fini = false;

	while (fini = false) {

		vector<grille> vec = { G1,G2 };
<<<<<<< Updated upstream
		//vec = jouer(G1, G2);
=======
		vec = jouer(G1, G2);
		cout << vec[1] << endl;
>>>>>>> Stashed changes

	}



}