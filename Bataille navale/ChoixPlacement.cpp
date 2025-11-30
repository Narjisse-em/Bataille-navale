#include "ChoixPlacement.h"
#include <iostream>
using namespace std;


void ChoixPlacement::lire_placement()
{
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

    cout << "Exemple : 4 1 V\n";
    cout << " → place un bateau qui part de (x=1, y=4) vers le bas.\n\n";

    cout << "IMPORTANT :\n";
    cout << " - Le bateau doit tenir entier dans la grille.\n";
    cout << " - Il ne doit pas chevaucher un autre bateau.\n";
    cout << " - Il ne doit pas sortir des limites.\n\n";
    cin >> choix.type >> choix.x >> choix.y >> choix.orientation;

    // Mise en forme
    for (char& c : choix.type) c = toupper(c);
    choix.orientation = toupper(choix.orientation);

    // Vérification du type
    while (choix.type != "P" &&
        choix.type != "T" &&
        choix.type != "CR" &&
        choix.type != "CT" &&
        choix.type != "S")
    {
        cout << "Type invalide. Reessayez (P, T, CR, CT, S) : ";
        cin >> choix.type;
        for (char& c : choix.type) c = toupper(c);
    }

    // Vérification X
    while (choix.x < 0 || choix.x > 9) {
        cout << "x doit etre entre 0 et 9. Reessayez : ";
        cin >> choix.x;
    }

    // Vérification Y
    while (choix.y < 0 || choix.y > 9) {
        cout << "y doit etre entre 0 et 9. Reessayez : ";
        cin >> choix.y;
    }

    // Vérification orientation
    while (choix.orientation != 'H' && choix.orientation != 'V') {
        cout << "Tapez H ou V : ";
        cin >> choix.orientation;
        choix.orientation = toupper(choix.orientation);
    }

    return choix;
}
