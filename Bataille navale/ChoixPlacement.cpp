#include "ChoixPlacement.h"
#include <iostream>
using namespace std;

ChoixPlacement ChoixPlacement::lire_placement(){
    ChoixPlacement choix;

    cout << "=============================================\n";
    cout << "        MODE PLACEMENT DES BATEAUX\n";
    cout << "=============================================\n\n";

    cout << "Vous allez placer vos bateaux sur la grille vide 10 x 10 ci-dessus\n\n";
    cout << "Pour chaque bateau, vous devrez entrer :\n";
    cout << "   - le type de bateau (CT, CR, P, S ou T°\n";
    cout << "   - la ligne (y)\n";
    cout << "   - la colonne (x)\n";
    cout << "   - l'orientation : H (horizontal) ou V (vertical)\n\n";

    cout << "Exemple : CR 4 1 V\n";
    cout << " → place un Croiseur qui part de (x=1, y=4) vers le bas.\n\n";

    cout << "IMPORTANT :\n";
    cout << " - Le bateau doit tenir entier dans la grille.\n";
    cout << " - Il ne doit pas chevaucher un autre bateau.\n";
    cout << " - Il ne doit pas sortir des limites.\n\n";
    cin >> choix.type >> choix.x >> choix.y >> choix.orientation;

    // Mise en forme
    for (char& c : choix.type) c = toupper(c);
    choix.orientation = toupper(choix.orientation);
    return choix;
}