#pragma once

#include<iostream>
#include<vector>
using namespace std;

class grille {
private:
	vector<vector<char>> lagrille;
public:
	grille() :lagrille(10, vector<char>(10, '~')) {}  // Initialisation de la grille avec des '~'

		// Ajout de l'operateur [] pour acc�der � lagrille comme un tableau 2D
		vector<char>& operator[](size_t index) {
			return lagrille[index];
		}
		const vector<char>& operator[](size_t index) const {
			return lagrille[index];
		}

		const vector<vector<char>>& getGrille() const;
};

//declaration de la surchage pour afficher la grille 
ostream& operator<<(ostream& os, const grille g);