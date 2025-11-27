#pragma once
class sousmarin :public bateau {
	int place = 3;
public:
	void decrem() { place -= 1; }
};