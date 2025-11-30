#pragma once
#include "bateau.h"

class torpilleur :public bateau {
public:
	torpilleur() :bateau(2, 'T') {}
};