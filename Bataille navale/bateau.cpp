#include<iostream>
#include <cstdlib>
#include "bateau.h"
using namespace std;


void bateau::placement(grille& g) {
	int x, y;
	bool horizontal;
	bool ok = false;

	while(!ok) {
		horizontal = rand() % 2;
		x = rand() % 10;
		y = rand() % 10;
		ok = true;

		if (horizontal) {
			if (x + longueur > 10) { ok = false; continue; }
			
			for (int i = 0; i < longueur; i++)
				if (g[y][x + i] != '~') ok = false;
		}
		else {
			if (y + longueur > 10) {ok = false; continue;}
			
			for (int i = 0; i < longueur; i++) {
				if (g[y + i][x] != '~') ok = false;
			}
		}

//placmeent final
	if (horizontal){
		for (int i=0; i<longueur; i++)
			g[y][x + i] = symbole;
	}
	else {
		for (int i=0; i<longueur; i++)
			g[y + i][x] = symbole;
		}
	}
}
