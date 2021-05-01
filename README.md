# __MiniProjet 2__
Olando Bazil 28608499
Cyrena Ramdani 3805942

## __Exercice 1__ 


## __Exercice 1__ 

Chaine.h contient les structures : 
 - CellPoint
 - CellChaine
 - Chaines

Et les fonctions des fichiers:
 - gestionChaine.c
 - Chaine.c
 - mesureChaine.c


Pour tester toutes les fonctions de l'exo1 il faut utiliser les commandes : *le nom de fichier html est facultatif*
```bash
make
./projet <Chaine_file> <nom_fichier_html> 
```
En ajoutant dans le makefile : ``ChaineMain.c``


Ce qui va 
- Ouvrir __Chaine_file__ et le lire pour creer une Chaine
- Ecrire dans le meme format dans un fichier  ``Data.txt``
- Creer un fichier SVG nommé ``<nom_fichier_html>.html`` ou ``nomInstance.html`` si le 2e parametre n'est pas précisé
- Compter le nombre total de point, la longueur de la 1ere chaine et de la longueur totale des chaines



## __Exercice 2__ 

Reseau.h contient les structures : 
 - CellNoeud
 - Noeud
 - CellCommodite
 - Reseau

Et les fonctions des fichiers:
 - gestionReseau.c
 - Reseau.c
 - ReconstitueReseau.c

Pour tester toutes les fonctions de l'exo2 il faut utiliser les commandes 
```bash
make
./projet <Chaine_file> <methode_Reseau = [1-3]> 
```
methode_reseau est un chiffre entre 1 et 3 qui determinera la maniere dont sera reconstitué le réseau:
- 1 : Liste
- 2 : Table de Hachage
- 3 : Arbre Quaternaire

En ajoutant dans le makefile : ``ReconstitueReseau.c``

Ce qui va 
- Verifier que tous les parametres sont correctes
- Ouvrir __Chaine_file__ et le lire pour creer une Chaine
- Reconstitue le reseau a partir de la chaine avec la methode choisie et l'ecrit dans un fichier ``Reconstitue.res``
- Afficher les caracteristiques lié a la chaine et au reseau (exo 1 - 3)

## __Exercice 3__ 

Les fonctions des fichiers:
 - Reseau.c
 - mesureReseau.c


Pour tester toutes les fonctions de l'exo3 il faut utiliser les commandes : *le nom de fichier html est facultatif*
```bash
make
./projet <Chaine_file> <nom_fichier_html> 
```
En ajoutant dans le makefile : ``ReseauMain.c``

Ce qui va 
- Ouvrir __Chaine_file__ et le lire pour creer une Chaine
- Reconstitue le reseau a partir de la chaine et l'ecrit dans un fichier ``Data.res``
- Creer un fichier SVG nommé ``<nom_fichier_html>.html`` ou ``nomInstance.html`` si le 2e parametre n'est pas précisé a partir de la chaine et du reseau obtenu pour faire la comparaison
- Compter le nombre de commodite, liaison et noeuds



## __Exercice 4__ 

2. pour des entiers de 1 a 10 on obtient

4 8 13 19 26 34 43 53 64 76 
7 12 18 25 33 42 52 63 75 88 
11 17 24 32 41 51 62 74 87 101 
16 23 31 40 50 61 73 86 100 115 
22 30 39 49 60 72 85 99 114 130 
29 38 48 59 71 84 98 113 129 146 
37 47 58 70 83 97 112 128 145 163 
46 57 69 82 96 111 127 144 162 181 
56 68 81 95 110 126 143 161 180 200 
67 80 94 109 125 142 160 179 199 220 

approprié? criteres...
4. Dans un premier temps on cherche si le Noeuds existe sinon on le crée tout en mettant a jour ses voisins. Retourne le resultat

Pour tester : utiliser ``ReconstitueReseau.c`` avec comme 2e parametre `2`


## __Exercice 5__

