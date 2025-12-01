#include<iostream>
#include"bateau.h"

using namespace std;

class torpilleur : public bateau{
    public:
        torpilleur() : bateau(2, 'T') {}
};