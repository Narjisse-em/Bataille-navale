#pragma once
class porteavion :public bateau {
	int place = 5;
public:
	void decrem() { place -= 1; }
};