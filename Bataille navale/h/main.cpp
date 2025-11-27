#include<iostream>

#pragma once
#include "C:\Users\elman\OneDrive\Documents\GitHub\Bataille-navale\Bataille navale\h\grille.h"
#include "C:\Users\elman\OneDrive\Documents\GitHub\Bataille-navale\Bataille navale\h\bateau.h"
#include "C:\Users\elman\OneDrive\Documents\GitHub\Bataille-navale\Bataille navale\h\contre-torpilleur.h"
#include "C:\Users\elman\OneDrive\Documents\GitHub\Bataille-navale\Bataille navale\h\croiseur.h"
#include "C:\Users\elman\OneDrive\Documents\GitHub\Bataille-navale\Bataille navale\h\porte-avion.h"
#include "C:\Users\elman\OneDrive\Documents\GitHub\Bataille-navale\Bataille navale\h\sous-marin.h"
#include "C:\Users\elman\OneDrive\Documents\GitHub\Bataille-navale\Bataille navale\h\torpilleur.h"
#include "C:\Users\elman\OneDrive\Documents\GitHub\Bataille-navale\Bataille navale\h\jeu.h"

#include "C:\Users\elman\OneDrive\Documents\GitHub\Bataille-navale\Bataille navale\src\bateau.cpp"
#include "C:\Users\elman\OneDrive\Documents\GitHub\Bataille-navale\Bataille navale\src\contre-torpilleur.cpp"
#include "C:\Users\elman\OneDrive\Documents\GitHub\Bataille-navale\Bataille navale\src\croiseur.cpp"
#include "C:\Users\elman\OneDrive\Documents\GitHub\Bataille-navale\Bataille navale\src\grille.cpp"
#include "C:\Users\elman\OneDrive\Documents\GitHub\Bataille-navale\Bataille navale\src\jeu.cpp"
#include "C:\Users\elman\OneDrive\Documents\GitHub\Bataille-navale\Bataille navale\src\porte-avion.cpp"
#include "C:\Users\elman\OneDrive\Documents\GitHub\Bataille-navale\Bataille navale\src\sous-marin.cpp"
#include "C:\Users\elman\OneDrive\Documents\GitHub\Bataille-navale\Bataille navale\src\initialisation.cpp"
#include "C:\Users\elman\OneDrive\Documents\GitHub\Bataille-navale\Bataille navale\src\torpilleur.cpp"


int main() {

	//initialisation des grilles
	//G1 humain tire robot place 
	//G1 robot tire humain place 

	grille G1 = grille();
	grille G2 = grille();

	bool fini = false;

	while (fini = false) {

		vector<grille> vec = { G1,G2 };
		vec = jouer(G1, G2);

	}



}