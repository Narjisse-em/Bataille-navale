#pragma once
#include "bateau.h"

class croiseur :public bateau {
	int place = 4;
public:
	croiseur() :bateau(4, 'C') {}
};