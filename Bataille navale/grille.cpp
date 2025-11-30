#include <vector>
#include <string>
#include "grille.h"



const vector<vector<char>>& grille::getGrille() const {
	return lagrille;
}

//declaration de la surchage pour afficher la grille 
ostream& operator<<(ostream& os, const grille& g) {
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++)
			os << g.lagrille[y][x] << ' ';
		os << '\n';
	}
	return os;
};
