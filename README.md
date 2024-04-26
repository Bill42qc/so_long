So_long

So_long est un projet de l'école 42 qui consiste à créer un jeu simple en utilisant la bibliothèque graphique minilibx. Le jeu est un défi amusant où le joueur doit ramasser des objets et éviter des ennemis tout en se déplaçant à travers un niveau.
Description

Le jeu So_long se déroule sur une carte composée de différents types de cases :

    0 : Espace vide
    1 : Mur
    C : Collectible (objet à collecter)
    E : Sortie (pour terminer le niveau)
    P : Personnage (joueur)
    E : Ennemi (optionnel)

Fonctionnalités

    Déplacements : Mouvements du personnage avec les touches directionnelles.
    Collectibles : Ramasser les objets collectibles pour marquer des points.
    Sortie : Atteindre la sortie pour terminer le niveau.
    Ennemis : Éviter les ennemis qui se déplacent aléatoirement.
    Cartes multiples : Possibilité de jouer sur plusieurs cartes.

Prérequis

    GCC (ou tout autre compilateur C compatible)
    minilibx (bibliothèque graphique)

Installation

    Clonez le dépôt :

bash

git clone https://github.com/votre-nom-utilisateur/so_long.git

    Accédez au répertoire du projet :

bash

cd so_long

    Compilez le jeu :

bash

make

Utilisation

Pour exécuter le jeu, utilisez la commande suivante :

bash

./so_long [map_path]

Exemple :

bash

./so_long maps/map1.ber

Contrôles

    Touches directionnelles : Déplacer le personnage (haut, bas, gauche, droite)
    Echap : Quitter le jeu

Contribution

Les contributions sont les bienvenues ! Pour des modifications majeures, veuillez ouvrir une issue pour discuter des changements proposés.
