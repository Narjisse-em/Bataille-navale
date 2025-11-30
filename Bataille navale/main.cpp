#include<iostream>
#include<vector>
#include<ctime>

#include "grille.h"
#include "bateau.h"
#include "contretorpilleur.h"
#include "croiseur.h"
#include "porteavion.h"
#include "sousmarin.h"
#include "torpilleur.h"
#include "jeu.h"
#include "utilities.h"
#include "ChoixPlacement.h"
#include "Tir.h"

using namespace std;

int main() {

	//initialise le générateur aléatoire pour placer les bateaux
	srand(time(NULL));

	//placements aléatoires dans la grille adverse
	grille g1;

	porteavion PA;
	croiseur CR;	
	contretorpilleur CT;
	sousmarin S;
	torpilleur T;

	PA.placement(g1);
	CR.placement(g1);
	CT.placement(g1);
	S.placement(g1);
	T.placement(g1);


	cout << "Grille avec les bateaux placés :" << endl;
	cout<<g1<< endl;


	


// Grille du joueur
    grille g2;

    // Compteurs : 1 bateau de chaque type
    int restant_P = 1;
    int restant_CR = 1;
    int restant_CT = 1;
    int restant_S = 1;
    int restant_T = 1;

    int total_a_placer = 5;

    while (total_a_placer > 0)
    {
        cout << "\n=============================================\n";
        cout << "       PLACEMENT DE VOS BATEAUX" << endl;
        cout << "=============================================\n";

        cout << "Bateaux restants :" << endl;
        cout << "  P  (5 cases)  : " << restant_P << endl;
        cout << "  CR (4 cases)  : " << restant_CR << endl;
        cout << "  CT (3 cases)  : " << restant_CT << endl;
        cout << "  S  (3 cases)  : " << restant_S << endl;
        cout << "  T  (2 cases)  : " << restant_T << endl;

        cout << "\nGrille actuelle :" << endl;
        cout << g2 << endl;

        // Lire un placement
        ChoixPlacement choix = ChoixPlacement::lire_placement();

        // Vérifier que ce type reste à placer
        bool deja_place = false;

        if (choix.getType() == "P" && restant_P == 0) deja_place = true;
        if (choix.getType() == "CR" && restant_CR == 0) deja_place = true;
        if (choix.getType() == "CT" && restant_CT == 0) deja_place = true;
        if (choix.getType() == "S" && restant_S == 0) deja_place = true;
        if (choix.getType() == "T" && restant_T == 0) deja_place = true;

        if (deja_place) {
            cout << "Vous avez déjà placé ce type de bateau !\n";
            continue;
        }

        // Déterminer longueur et symbole
        int L = 0;
        char symbole = '?';

        if (choix.getType() == "P") { L = 5; symbole = 'P'; }
        if (choix.getType() == "CR") { L = 4; symbole = 'C'; }
        if (choix.getType() == "CT") { L = 3; symbole = 'K'; }
        if (choix.getType() == "S") { L = 3; symbole = 'S'; }
        if (choix.getType() == "T") { L = 2; symbole = 'T'; }

        // Vérifier validité
        if (!placement_valide(g2, choix.getX(), choix.getY(), choix.getOrientation(), L)) {
            cout << "Placement impossible : hors grille OU chevauchement !\n";
            continue;
        }

        // Placer
        placer_bateau(g2, choix.getX(), choix.getY(), L, choix.getOrientation(), symbole);

        cout << "==> Bateau place !" << endl;

        // Décrémente le bon compteur
        if (choix.getType() == "P")  restant_P--;
        if (choix.getType() == "CR") restant_CR--;
        if (choix.getType() == "CT") restant_CT--;
        if (choix.getType() == "S")  restant_S--;
        if (choix.getType() == "T")  restant_T--;

        total_a_placer--;
    }

    cout << "\n====== VOTRE GRILLE FINALE ======\n";
    cout << g2 << endl;

    bool fini = false;

    cout << "\n===== DEBUT DU COMBAT ! =====\n";

    grille vueOrdi;       // ce que le joueur voit de l’ordinateur
    grille vueJoueur;     // ce que l’ordinateur voit du joueur
    // initialisés avec '~'

    while (!fini)
    {
        cout << "\n----- Votre tir -----\n";

        // 1. Le joueur tire
        Tir tirJ = lire_tir_joueur();

        ResultatTir res = evaluer_tir(g1, tirJ.x, tirJ.y);

        if (res == A_L_EAU) cout << "A L'EAU !\n";
        if (res == TOUCHE)  cout << "TOUCHE !\n";
        if (res == COULE)   cout << "COULE !\n";

        // Mettre à jour la vue du joueur
        vueOrdi[tirJ.y][tirJ.x] = g1[tirJ.y][tirJ.x];

        cout << "Votre vue de l'adversaire :\n" << vueOrdi;


        // 2. Vérifier si l'ordinateur a perdu
        bool ordi_mort = true;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                if (g1[i][j] != '~' && g1[i][j] != 'X' && g1[i][j] != 'O')
                    ordi_mort = false;

        if (ordi_mort) {
            cout << "\n=== VICTOIRE ! Vous avez coulé toute la flotte adverse ! ===\n";
            break;
        }


        // ------- Tir de l’ordinateur -------
        cout << "\n----- Tir de l'ordinateur -----\n";

        Tir tirO = tir_ordi(vueJoueur);

        ResultatTir res2 = evaluer_tir(g2, tirO.x, tirO.y);

        if (res2 == A_L_EAU) cout << "L'ordinateur a tire dans l'eau.\n";
        if (res2 == TOUCHE)  cout << "L'ordinateur vous a touche !\n";
        if (res2 == COULE)   cout << "L'ordinateur a coule un de vos bateaux !\n";

        vueJoueur[tirO.y][tirO.x] = g2[tirO.y][tirO.x];


        bool joueur_mort = true;
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                if (g2[i][j] != '~' && g2[i][j] != 'X' && g2[i][j] != 'O')
                    joueur_mort = false;

        if (joueur_mort) {
            cout << "\n=== DÉFAITE ! Votre flotte est détruite... ===\n";
            break;
        }
    }




	//fin du programme
	return 0;
}