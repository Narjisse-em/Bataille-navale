#pragma once

class contretorpilleur :public bateau {
	int place = 3;
public:
	void decrem() { place -= 1; }
};