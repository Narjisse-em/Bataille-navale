#pragma once

#include<iostream>
#include<vector>
using namespace std;

class grille {
	protected:
		vector<vector<char>> lagrille;
	public:
		grille();

		// Ajout de l'operateur [] pour accï¿½der ï¿½ lagrille comme un tableau 2D
		vector<char>& operator[](size_t index) {
			return lagrille[index];
		}
		const vector<char>& operator[](size_t index) const {
			return lagrille[index];
		}

<<<<<<< Updated upstream
		const vector<vector<char>>& getGrille() const;
};

//declaration de la surchage pour afficher la grille 
ostream& operator<<(ostream& os, const grille g);
=======
		void print(std::ostream& os) const;  // MÉTHODE D’AFFICHAGE

		// surcharge <<
		friend std::ostream& operator<<(std::ostream& os, const grille& g);
};
>>>>>>> Stashed changes
