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
#include "utilities.h"
#include "ChoixPlacement.h"

using namespace std;

int main() {

	//initialise le générateur aléatoire pour placer les bateaux
	srand(time(NULL));

	//placements aléatoires dans la grille adverse
	grille g1;

	porteavion PA;
	croiseur CR;	
	contretorpilleur CT;
	sousmarin S;
	torpilleur T;

	PA.placement(g1);
	CR.placement(g1);
	CT.placement(g1);
	S.placement(g1);
	T.placement(g1);


	cout << "Grille avec les bateaux placés :" << endl;
	cout<<g1<< endl;


	//placements à la main dans la grille du joueur
	grille g2;
	ChoixPlacement choix = ChoixPlacement::lire_placement();

	// déterminer longueur + symbole selon type

	int L = 0;
	char symbole = ' ';
	bool type_invalide=true ;
	while(type_invalide){
		if (choix.getType() == "P") {  L = 5;  symbole = 'P'; type_invalide=false; }
		else if (choix.getType() == "CR") { L = 4; symbole = 'C'; type_invalide=false; }
		else if (choix.getType() == "CT") { L = 3; symbole = 'K'; type_invalide=false; }
		else if (choix.getType() == "S") { L = 3; symbole = 'S'; type_invalide=false; }
		else if (choix.getType() == "T") { L = 2; symbole = 'T'; type_invalide = false; }
		
		else {cout << "Type de bateau invalide ! Veuillez entrer un type valide (P, CR, CT, S, T) :" << endl;
		 choix = ChoixPlacement::lire_placement();
		}
	}
	
	if (placement_valide(g2, choix.getX(), choix.getY(), choix.getOrientation(), L)) {
		placer_bateau(g2, choix.getX(), choix.getY(), L, choix.getOrientation(), symbole);
		cout << "Placement réussi !" << endl;
	}
	else {
		cout << "Placement invalide !" << endl;
	}


	//fin du programme
	return 0;
}