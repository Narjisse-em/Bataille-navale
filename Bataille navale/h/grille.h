#pragma once

#include<iostream>
#include<vector>
using namespace std;

class grille {
	protected:
		vector<vector<char>> lagrille;
	public:
		grille();

		// Ajout de l'op�rateur [] pour acc�der � lagrille comme un tableau 2D
		vector<char>& operator[](size_t index) {
			return lagrille[index];
		}
		const vector<char>& operator[](size_t index) const {
			return lagrille[index];
		}
};