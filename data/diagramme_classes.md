# Diagramme de classe UML

```mermaid
classDiagram

%% ============================
%% Classes
%% ============================

class grille {
    - lagrille : vector<vector<char>>
    + grille()
    + operator[](index) : vector<char>&
    + getGrille() : const vector<vector<char>>&
}

class bateau {
    - longueur : int
    - symbole : char
    + bateau(L:int, S:char)
    + getL() : int
    + getSymbole() : char
    + placement(g:grille) : void
}

class ChoixPlacement {
    - type : string
    - x : int
    - y : int
    - orientation : char
    + getType() : string
    + getX() : int
    + getY() : int
    + getOrientation() : char
    + lire_placement() : ChoixPlacement
}

class Tir {
    - x : int
    - y : int
}

class utilities {
    <<module>>
    + placement_valide(g:grille, x:int, y:int, o:char, L:int) : bool
    + placer_bateau(g:grille, x:int, y:int, L:int, o:char, S:char) : void
    + lire_tir_joueur() : Tir
    + tir_ordi(vue:grille) : Tir
    + evaluer_tir(g:grille, x:int, y:int) : ResultatTir
}

class ResultatTir {
    <<enumeration>>
    A_L_EAU
    TOUCHE
    COULE
}

class main {
    <<program>>
}

%% ============================
%% Relations UML + Multiplicités
%% ============================

%% main possède 2 grilles
main "1" o-- "2" grille : possède

%% main instancie 5 bateaux
main "1" --> "5" bateau : instancie

%% main lit un ChoixPlacement (1 par placement)
main "1" --> "1" ChoixPlacement : lit

%% ChoixPlacement correspond à 1 bateau à placer
ChoixPlacement "1" --> "1" bateau : décrit

%% 1 bateau modifie exactement 1 grille
bateau "1" *-- "1" grille : modifie

%% Une grille contient 100 cases char
grille "1" o-- "100" char : cases

%% main utilise la classe Tir et les fonctions qui en retournent
main "1" --> "1" Tir : utilise

%% utilities utilise / lit / modifie une grille
utilities ..> grille : lit/modifie

%% utilities crée et retourne des Tir
utilities ..> Tir : retourne

%% utilities retourne un enum ResultatTir
utilities ..> ResultatTir : retourne
