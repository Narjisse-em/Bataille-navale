#include <vector>
#include <string>
#include "grille.h"

grille::grille() {
	vector<vector<char>> lagrille;
	for (int i = 0; i < 10; i++) {
		vector<char> v;
		for (int j = 0; j < 10; j++) {
			v.push_back('V');
		}
		lagrille.push_back(v);
	}
}

const vector<vector<char>>& grille::getGrille() const {
	return lagrille;
}

ostream& operator<<(ostream& os, const grille& g)
{
	// TODO: insérer une instruction return ici
}

ostream& operator<<(ostream& os, const grille g) {
	const auto& m = g.getGrille();


	//syntaxe dans le for : on definit ligne ou c comme chaque élément de m ou ligne
	// très pratique :)

	for (const auto& ligne : m) {
		for (char c : ligne) {
			os << c;

		}
		os << "\n";
	}

	return os;
}

