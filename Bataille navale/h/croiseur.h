#pragma once
class croiseur :public bateau {
	int place = 4;
public:
	void decrem() { place -= 1; }
};