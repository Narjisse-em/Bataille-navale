

#include<iostream>
#include <cstdlib>
using namespace std;

#include "include.h"

void bateau::placement() {
	bool bien_place = false;
	grille g;
	while (!bien_place) {
		int randomNum = rand() % (11-length);
		//horizontalement
		for (int i = randomNum; i < randomNum + length; i++) {
			for (int j = randomNum; j < randomNum + length; j++) {
				if (g[i][j]=="V"){
					bien_place = false;
		}
	}

}
