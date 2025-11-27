#include "grille.h"

grille::grille() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			vector<char> v;
			v.push_back("V");
		}
		lagrille.push_back(v);
	}
}

