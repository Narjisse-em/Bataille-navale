#pragma once
#include <string>
using namespace std;

struct ChoixPlacement {
private:    
    string type="";       // P, T, CR, CT, S
    int x=0;
    int y=0;
    char orientation='H';  // H ou V
public:

	//getteurs
	string getType() const { return type; }
	int getX() const { return x; }
	int getY() const { return y; }
	char getOrientation() const { return orientation; }

	static ChoixPlacement lire_placement();
    };
