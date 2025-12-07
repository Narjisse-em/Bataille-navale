#include "ChoixPlacement.h"
#include <iostream>
using namespace std;

ChoixPlacement ChoixPlacement::lire_placement() {

	ChoixPlacement choix;
	string type;   // on lit d'abord une string pour éviter de lire des erruers comme "T5" et causer des bugs
	int x, y;
	char orientation;

	while (true) {

		cout << "Entrez : type x y orientation (ex: C 4 1 V) : ";
		cin >> type >> x >> y >> orientation;

		// Erreur de saisie -> vide le buffer et recommence
		if (!cin) {
			cin.clear();
			cin.ignore(9999, '\n');
			cout << "Saisie invalide. Reessayez.\n";
			continue;
		}

		// Vérifier que type est une LETTRE seule
		if (type.size() != 1) {
			cout << "Type invalide. Entrez une seule lettre (C,K,P,S,T).\n";
			continue;
		}

		char t = toupper(type[0]);

		if (t != 'C' && t != 'K' && t != 'P' && t != 'S' && t != 'T') {
			cout << "Type invalide.\n";
			continue;
		}

		// Vérifier coordonnées
		if (x < 0 || x >= 10 || y < 0 || y >= 10) {
			cout << "Coordonnees invalides.\n";
			continue;
		}

		orientation = toupper(orientation);
		if (orientation != 'H' && orientation != 'V') {
			cout << "Orientation invalide.\n";
			continue;
		}

		// ------------------------
		// Tout est valide → on renvoie
		// ------------------------
		choix.type = t;
		choix.x = x;
		choix.y = y;
		choix.orientation = orientation;
		return choix;
	}
}
