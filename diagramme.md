classDiagram

class grille {
    - vector<vector<char>> lagrille
    + grille()
    + operator[](size_t) vector<char>&
    + getGrille() const vector<vector<char>>&
}

class bateau {
    - int longueur
    - char symbole
    + bateau(int L, char S)
    + getL() int
    + getSymbole() char
    + placement(grille&) void
}

class ChoixPlacement {
    - string type
    - int x
    - int y
    - char orientation
    + getType() string
    + getX() int
    + getY() int
    + getOrientation() char
    + lire_placement() ChoixPlacement
}

class Tir {
    - int x
    - int y
}

class utilities {
    <<module>>
    + placement_valide(grille&, int, int, char, int) bool
    + placer_bateau(grille&, int, int, int, char, char) void
    + lire_tir_joueur() Tir
    + tir_ordi(grille&) Tir
    + evaluer_tir(grille&, int, int) ResultatTir
}

class ResultatTir {
    <<enum>>
    A_L_EAU
    TOUCHE
    COULE
}

main --> ChoixPlacement : utilise
main --> grille : utilise
main --> bateau : instancie
main --> Tir : utilise

utilities --> grille : manipule
utilities --> Tir : retourne
utilities --> ResultatTir : retourne
bateau --> grille : placement()
