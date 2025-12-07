#include <vector>
#include <string>
#include "grille.h"


const vector<vector<char>>& grille::getGrille() const {
	return lagrille;
}

//declaration de la surchage pour afficher la grille 
ostream& operator<<(ostream& os, const grille& g) {

	//chiffres du dessus pour les coordonnées en x
	os << "   ";
	for (int x = 0; x < 10; x++)
	{
		os <<  x << " ";
	}

	//cases et coordonnées y
	os << "\n";
	for (int y = 0; y < 10; y++) {
		os << " " << y << "|";//index ligne côté gauche

		for (int x = 0; x < 10; x++)
		{
			os << g.lagrille[y][x] << "|";
		}
		os << " " << y ;//index ligne côté droit

		os << "\n";
	};

	//chiffres du dessous pour les coordonnées en x
	os << "   ";
	for (int x = 0; x < 10; x++)
	{
		os << x << " ";
	}
	return os;
}
