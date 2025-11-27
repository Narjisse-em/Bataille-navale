#include <iostream>
#include "jeu.h"
#include "C:\Users\elman\OneDrive\Documents\GitHub\Bataille-navale\Bataille navale\h\grille.h"
#include <random>
using namespace std;

grille jouer (grille G1, grille G2) {


	//G1 = grille où l'humain tire avec bateaux ordi
	//test d'arrêt
	int i = 0;

	while (i == 0) {

		// tour de l'humain
		int xA;
		int yA;

		cout << "en quel x voulez vous attaquer?";
		cin >> xA;

		cout << " en quel y voulez vous attaquer";
		cin >> yA;

		//test si case déjà tenté
		if (G1[xA][yA] == 'X' || G1[xA][yA] == 'O') {
			cout << "case déjà faite" << endl;
		}

		//sinon on actualise
		else {

			//la case a un bateau
			if (G1[xA][yA] == 'B') {
				cout << "TOUCHEEEE" << endl;
				G1[xA][yA] = 'X';
				i = 1;
			}

			//la case est vide	
			if (G1[xA][yA] == 'V') {
				cout << "RATE" << endl;
				G1[xA][yA] = 'O';
				i = 1;
			}
		}
	}

	//tour de l'ordi 
	//G2 = grille où l'ordi tire avec bateaux de l'humain
	


	while (i == 0) {

		random_device rd;          // source d'entropie
		mt19937 gen(rd());         // moteur RNG (Mersenne Twister)
		uniform_int_distribution<int> dist(0, 9); // a et b inclus

		int xA = dist(gen);
		int yA = dist(gen);

		if (G2[xA][yA] == 'X' || G2[xA][yA] == 'O') {
				i==0;
		}

		else {

			//la case a un bateau
			if (G2[xA][yA] == 'B') {
				cout << "L'ordi vous a eu HAHAHA" << endl;
				G2[xA][yA] = 'X';
				i = 1;
			}

			//la case est vide	
			if (G2[xA][yA] == 'V') {
				cout << "l'ordi ne vous a pas eu... OUF!" << endl;
				G2[xA][yA] == 'O';
				i = 1;
			}
		}
	}
}

