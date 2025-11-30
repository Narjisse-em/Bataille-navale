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

using namespace std;

int main() {

	//initialise le générateur aléatoire pour placer les bateaux
	srand(time(NULL));

	grille g;

	porteavion p;
	croiseur c;	
	contretorpilleur ct;
	sousmarin s;
	torpilleur t;

	p.placement(g);
	c.placement(g);
	ct.placement(g);
	s.placement(g);
	t.placement(g);


	cout << "Grille avec les bateaux placés :" << endl;
	cout<<g<< endl;

	//fin du programme
	return 0;


	bool fini = false;

	while (fini = false) {

		
	}



}