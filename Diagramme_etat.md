```mermaid
stateDiagram-v2
direction LR

[*] --> PlacementBateaux

state PlacementBateaux {
    direction LR
    [*] --> EnCoursPlacement
    EnCoursPlacement --> EnCoursPlacement : placement invalide
    EnCoursPlacement --> PlacementValide : placement OK
    PlacementValide --> EnCoursPlacement : reste bateaux
    PlacementValide --> FinPlacement : tous placés
}

FinPlacement --> TourJoueur

TourJoueur --> TirJoueur
TirJoueur --> AnalyseResultatJoueur

state AnalyseResultatJoueur {
    direction LR
    [*] --> EauJoueur
    EauJoueur --> FinAnalyseJoueur
    [*] --> ToucheJoueur
    ToucheJoueur --> FinAnalyseJoueur
    [*] --> CouleJoueur
    CouleJoueur --> FinAnalyseJoueur
}

FinAnalyseJoueur --> Victoire : flotte adverse détruite
FinAnalyseJoueur --> TourOrdi : continue

TourOrdi --> TirOrdi
TirOrdi --> AnalyseResultatOrdi

state AnalyseResultatOrdi {
    direction LR
    [*] --> EauOrdi
    EauOrdi --> FinAnalyseOrdi
    [*] --> ToucheOrdi
    ToucheOrdi --> FinAnalyseOrdi
    [*] --> CouleOrdi
    CouleOrdi --> FinAnalyseOrdi
}

FinAnalyseOrdi --> Defaite : flotte du joueur détruite
FinAnalyseOrdi --> TourJoueur : continue

Victoire --> [*]
Defaite --> [*]
