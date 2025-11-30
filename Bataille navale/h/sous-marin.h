#pragma once
#include "bateau.h"
class sousmarin :public bateau {
public:
	sousmarin() :bateau(3, 'S') {} //S = Sous-marin
};