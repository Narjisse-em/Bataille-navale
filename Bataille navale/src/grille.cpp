#include <vector>
#include <string>
#include "C:\Users\elman\OneDrive\Documents\GitHub\Bataille-navale\Bataille navale\h\grille.h"

grille::grille() {
	vector<vector<char>> lagrille;
	for (int i = 0; i < 10; i++) {
		vector<char> v;
		for (int j = 0; j < 10; j++) {
			v.push_back('V');
		}
		lagrille.push_back(v);
	}
}

