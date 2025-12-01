#include<iostream>
#include"bateau.h"

using namespace std;

class contretorpilleur : public bateau{
    public:
        contretorpilleur() : bateau(3, 'K') {}
};