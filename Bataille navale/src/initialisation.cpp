#include "bateau.h"
#include "grille.h"

int main() {

	//initialisation de la grille
	Grille grille;
	grille.afficher();

	//initialisation des bateaux
	cin >> "Initialisez vos bauteaux : "
		>> "\nPorte avion : " >> porteAvion.coordonnee
		>> "\nCroiseur : " >> croiseur.coordonnee
		>> "\nContre torpilleur : " >> contreTorpilleur.coordonnee
		>> "\nSous marin : " >> sousMarin.coordonnee
		>> "\nTorpilleur : " >> endl;

	//
	while (gagnat = FALSE) {

	}
	grille.placerBateau(bateau1, 0, 0, 'H');
	grille.placerBateau(bateau2, 2, 2, 'V');
	grille.afficher();
	return 0;
}
