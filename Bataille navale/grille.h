#pragma once

#include<iostream>
#include<vector>
using namespace std;

class grille {
private:
	vector<vector<char>> lagrille;
public:
	grille() :lagrille(10, vector<char>(10, '~')) {}  // Initialisation de la grille avec des '~'

	// Ajout de l'operateur [] pour accéder à lagrille comme un tableau 2D
	vector<char>& operator[](size_t index) { return lagrille[index]; }

	const vector<char>& operator[](size_t index) const { return lagrille[index]; }

	const vector<vector<char>>& getGrille() const;

	//declaration de la surchage pour afficher la grille 
	friend ostream& operator<<(ostream& os, const grille& g) {
		for (int y = 0; y < 10; y++) {
			for (int x = 0; x < 10; x++)
				os << g.lagrille[y][x] << ' ';
			os << '\n';
		}
		return os;
	};
};