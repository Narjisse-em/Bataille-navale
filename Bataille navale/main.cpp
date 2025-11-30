#include<iostream>
#include<vector>
#include<ctime>

#include "grille.h"
#include "bateau.h"
#include "contretorpilleur.h"
#include "croiseur.h"
#include "porteavion.h"
#include "sousmarin.h"
#include "torpilleur.h"
#include "jeu.h"
#include "utilities.cpp"

using namespace std;

int main() {

	//initialise le générateur aléatoire pour placer les bateaux
	srand(time(NULL));

	//placements aléatoires dans la grille adverse
	grille g1;

	porteavion p;
	croiseur c;	
	contretorpilleur ct;
	sousmarin s;
	torpilleur t;

	p.placement(g1);
	c.placement(g1);
	ct.placement(g1);
	s.placement(g1);
	t.placement(g1);


	cout << "Grille avec les bateaux placés :" << endl;
	cout<<g1<< endl;


	//placements à la main dans la grille du joueur
	grille g2;



	if (placement_valide(g2, int x, int y, oriantation, b))
	p.placement(g2);
	cout << "Grille du joueur avec les bateaux placés :" << endl;

	//fin du programme
	return 0;


	bool fini = false;

	while (fini = false) {

		
	}



}