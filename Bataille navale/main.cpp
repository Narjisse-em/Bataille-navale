#include<iostream>
#include<vector>
#include<ctime>

#include "grille.h"
#include "bateau.h"
#include "utilities.h"
#include "ChoixPlacement.h"
#include "Tir.h"

using namespace std;

int main() {

    // Initialisation du générateur aléatoire
    srand(static_cast<unsigned int>(time(NULL)));

	// placement aléatoire des bateaux de l'adversaire
    grille g1;

    bateau PA=bateau(5,'P');  // porte-avion
    bateau CR=bateau(4,'C');  // croiseur
    bateau CT=bateau(3,'K');  // contre-torpilleur
    bateau S=bateau(3,'S');  // sous-marin
    bateau T=bateau(2,'T');  // torpilleur
    vector<bateau> bateaux = {PA, CR, CT, S, T};

    for (bateau elt : bateaux) {
        bool place = false;
        while (!place)
        {
            int x = rand() % 10;
            int y = rand() % 10;
            char orientation = (rand() % 2 == 0) ? 'H' : 'V';
            int L = elt.getL();

            if (placement_valide(g1, x, y, orientation, L)) {
                place = true;
                placer_bateau(g1, x, y, L, orientation, elt.getSymbole());
            }
        }
    }
    cout << "Grille de l'adversaire (debug) :" << endl;
    cout << g1 << endl;

	// placement du jouer à la main

    grille g2;

    // Un seul exemplaire de chaque bateau
    int restant_P = 1;
    int restant_CR = 1;
    int restant_CT = 1;
    int restant_S = 1;
    int restant_T = 1;

    int total_a_placer = 5;

    while (total_a_placer > 0)
    {
        cout << "\n=============================================\n";
        cout << "            PLACEMENT DE VOS BATEAUX\n";
        cout << "=============================================\n";

        cout << "Bateaux restants :" << endl;
        cout << "  P : Porte_avion (5 cases)  : " << restant_P << endl;
        cout << "  C : Croiseur (4 cases)  : " << restant_CR << endl;
        cout << "  K : Contre-toprilleur (3 cases)  : " << restant_CT << endl;
        cout << "  S : Sous-marin (3 cases)  : " << restant_S << endl;
        cout << "  T : Torpilleur (2 cases)  : " << restant_T << endl;

        cout << "\nGrille actuelle :" << endl;
        cout << g2 << endl;

        // Lecture saisie utilisateur
        ChoixPlacement choix = ChoixPlacement::lire_placement();

        // Vérification qu'on n'essaie pas de placer un type déjà utilisé
        bool deja_place = false;

        if (choix.getType() == "P" && restant_P == 0) deja_place = true;
        if (choix.getType() == "C" && restant_CR == 0) deja_place = true;
        if (choix.getType() == "K" && restant_CT == 0) deja_place = true;
        if (choix.getType() == "S" && restant_S == 0) deja_place = true;
        if (choix.getType() == "T" && restant_T == 0) deja_place = true;

        if (deja_place) {
            cout << "Vous avez déjà placé ce type de bateau.\n";
            continue;
        }

        // Détermination de la longueur et du symbole associé
        int L = 0;
        char symbole = '?';

        if (choix.getType() == "P") { L = 5; symbole = 'P'; }
        if (choix.getType() == "C") { L = 4; symbole = 'C'; }
        if (choix.getType() == "K") { L = 3; symbole = 'K'; }
        if (choix.getType() == "S") { L = 3; symbole = 'S'; }
        if (choix.getType() == "T") { L = 2; symbole = 'T'; }

        // Vérification avant placement
        if (!placement_valide(g2, choix.getX(), choix.getY(), choix.getOrientation(), L)) {
            cout << "Placement impossible (chevauchement ou hors grille)." << endl;
            continue;
        }

        // Placement effectif
        placer_bateau(g2, choix.getX(), choix.getY(), L, choix.getOrientation(), symbole);
        cout << "Bateau place avec succes.\n";

        // Mise à jour du compteur
        if (choix.getType() == "P")  restant_P--;
        if (choix.getType() == "C") restant_CR--;
        if (choix.getType() == "K") restant_CT--;
        if (choix.getType() == "S")  restant_S--;
        if (choix.getType() == "T")  restant_T--;

        total_a_placer--;
    }

    cout << "\n====== VOTRE GRILLE FINALE ======\n";
    cout << g2 << endl;


	//fin de l'initialisation -> on passe à la boucle de tir

    cout << "\n===== DEBUT DU COMBAT ! =====\n";

    grille vueOrdi;     // ce que VOUS voyez de la grille adverse
    grille vueJoueur;   // ce que l’ORDI sait de votre grille

    bool fini = false;

    while (!fini)
    {
		// tour du joueur
        cout << "\n=========== VOTRE TOUR ===========\n";

        Tir tirJ = lire_tir_joueur();
        ResultatTir res = evaluer_tir(g1, tirJ.x, tirJ.y);

        if (res == ResultatTir::A_L_EAU)  cout << "A L'EAU.\n";
        if (res == ResultatTir::TOUCHE)   cout << "TOUCHE !\n";
        if (res == ResultatTir::COULE)    cout << "COULE !\n";

        // Mise à jour de la vue
        vueOrdi[tirJ.y][tirJ.x] = g1[tirJ.y][tirJ.x];

        cout << "\n--- Votre vue de l’adversaire ---\n";
        cout << vueOrdi << endl;

        // Vérification si l’ordi a perdu
        bool ordi_mort = true;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                if (g1[i][j] != '~' && g1[i][j] != 'X' && g1[i][j] != 'O')
                    ordi_mort = false;

        if (ordi_mort) {
            cout << "\n=== VICTOIRE ! Toute la flotte adverse est coulee. ===\n";
            break;
        }


        // tour de l'ordinateur
        cout << "\n=========== TOUR DE L’ORDINATEUR ===========\n";

        Tir tirO = tir_ordi(vueJoueur);

        cout << "L’ordinateur tire en : (" << tirO.x << ", " << tirO.y << ")\n";

        ResultatTir res2 = evaluer_tir(g2, tirO.x, tirO.y);

        if (res2 == ResultatTir::A_L_EAU)  cout << "L’ordinateur a rate." << endl;
        if (res2 == ResultatTir::TOUCHE)   cout << "L’ordinateur vous a touche." << endl;
        if (res2 == ResultatTir::COULE)    cout << "L’ordinateur a coule un de vos bateaux !" << endl;

        vueJoueur[tirO.y][tirO.x] = g2[tirO.y][tirO.x];

        cout << "\n--- Votre grille (avec impacts) ---\n";
        cout << g2 << endl;

        cout << "\n--- Ce que l’ordi sait de votre grille ---\n";
        cout << vueJoueur << endl;

        // Vérification si le joueur a perdu
        bool joueur_mort = true;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                if (g2[i][j] != '~' && g2[i][j] != 'X' && g2[i][j] != 'O')
                    joueur_mort = false;

        if (joueur_mort) {
            cout << "\n=== DEFAITE ! Votre flotte est detruite. ===\n";
            break;
        }
    }
    return 0;
}

