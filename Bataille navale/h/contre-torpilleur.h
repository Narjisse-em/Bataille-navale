#pragma once
#include "bateau.h"

class contretorpilleur :public bateau {
public:
	contretorpilleur() :bateau(3, 'K') {} //K=contretorpilleur
};