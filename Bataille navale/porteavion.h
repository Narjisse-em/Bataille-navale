#pragma once
#include "bateau.h"

class porteavion :public bateau {
public:
	porteavion() :bateau(5, 'P') {} //P = Porte-avion
};