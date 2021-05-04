# __MiniProjet 1__
Olando Bazil 28608499
Cyrena Ramdani 3805942

## Usage 

Comment utiliser le script permettant de tester chaque exercice :

```bash
bash ./script
```

## Sommaire

- script.sh 

1. Exercice 1

- tme1_exo1p1.c
- tme1_exo1p2.c
- tme1_exo1p3.c

2. Exercice 2

- header.h
- Calcul_somme2.png : contient calculs effectués pour somme_carrés2
- tme1_exo2p1.c
- tme1_exo2p1_voir_resultat_somme.c
- tme1_exo2p2.c
- tme1_exo2p2_5.c
- tme1_exo2p2_5_voir_matrice.c
- tme1_exo2p2_6.c
- tme1_exo2p2_6_voir_produit.c


3. Fichiers générés par tests:

- courbe_Exercice2_somme.txt
- dataTousDiff.txt
- dataTousDiff2.txt
- dataProduit.txt

4. Courbes générées par GNUPLOT:

- 01_courbes_vitesse.png
- courbe_TousDiff.png
- courbe_TousDiff2.png
- courbe_Produit.png


## __Exercice 1__ 

### __Partie 1__ : probleme avec l'indice de boucle

### Question 1

- Le programme est cense allouer un tableau de 10 cases avec des int dans l'ordre decroissant (de 9 a 0). 
- Or on obtient un segfault


### Question 2

- Comme i est un unsigned int il ne peut pas prendre de valeur negative. 
- La condition ``i >= 0 `` dans la boucle for fait que i prend la valeur de INT_MAX (4294967295) après l'itération dans laquelle i valait 0
	-	Pour sortir de la boucle i devrait prendre une valeur négative.
- On essaye donc d'accéder à la case du tableau 4294967295, or nous avons alloue uniquement 10 cases, on essaye alors d'atteindre une memoire qui ne nous appartient d'ou l'erreur de segmentation.

- GDB affiche alors : 
```text
(gdb) r
Program received signal SIGSEGV, Segmentation fault.
0x00005555555551bf in main () at tme1_exo1p1.c:13
13			tab[i] = i;
(gdb) p i
$1 = 4294967295
```


### Question 3
- Il suffit de ne pas initialiser i comme étant un unsigned int mais un int simple
- Ou ajouter l'instruction a la fin de la boucle for :
```C
if (i == 0)
	break;
```

### __Partie 2__ : problème d'allocation mémoire

### Question 4

- À la lecture du code, le programme est censé créé un pointeur vers une adresse qui le met dans maison, et affiche les 3 champs de cette adresse.
- Lorsque l'on compile et que l'on lance le programme, on obtient une erreur de segmentation.e

### Question 5

- Lorsque l'on affiche la valeur de new-rue on a :
```text
(gdb) p new->rue
$1 = 0x0
```
Ce qui correspond a une adresse NULL car lors de l'appel de fonction ``creer_adresse`` on ne lui alloue pas de memoire. 

- En continuant l'exécution pour arriver au deuxième point d'arrêt remarque que l'erreur apparaît
- L'erreur provient de la ligne 15 ``strcpy(new->rue, r);`` En effet, la variable ``new->rue`` n'est pas initialise, donc la fonction copie r dans une adress aleatoire.
	- Pour corriger cette erreur on peut, soit allouer dynamiquement avec l'instruction ``new->rue=strdup(r);`` dans la fonction ``creer_addresse``
	- Ou on declare un tableau statique ``new->rue`` dans la structure (par exemple : ``char rue[100];``) 

### __Partie 3__ : fuite mémoire


### Question 6

- Le programme est censé faire une structure tableau, d'ajouter des éléments à cette structure, et à les afficher.
- Lorsque l'on lance le programme, on obtient :
```
t->position = 5 
[ 5 18 99999 -452 4587 ]
```

### Question 7

- Le problème de ce programme est que l'on alloue de la memoire pour la structure ``Tableau`` et aussi pour le tableau d'int ``tab`` qu'il contient auquel on a alloue ``sizeof(int)*maxTaille``
- Or que l'on ne libere pas toute la mémoire :
	- on libere uniquement la mémoire de la stucture ``Tableau`` 
	- on ne libere pas la memoire de ``t->tab``


### Question 8

- On constate que Valgrind repere des leak dans notre programme.
- Les 400bytes relevés correspondent a ``sizeof(int)*maxTaille`` que l'on a alloue pour ``t->tab`` mais que l'on a pas free.


### Question 9

Les corrections possibles sont : 
- Avoir un tableau static dans la structure ``Tableau`` (mais on ne pourra pas rentrer sa taille max au moment de l'initialisation du tableau)
- Liberer la memoire du tableau d'int avant de liberer celle de la structure en ajoutant la ligne :
```C
free(t->tab);
``` 


## __Exercice__ 2

### __Partie 1__ : Tableau à une dimension 


### Question 1

1. __alloue_matrice__

- La version qui retourne un tableau alloué est plus intuitive et cela nous permet d'economiser des lignes.
	- Dans la version avec un passage de reference on est obligé de creer un tableau d'int avant.

```c
int **alloue_matrice(int n){
  int **tab = malloc(sizeof(int *) * n);
  
  for (int i = 0; i < n; i++)
    tab[i] = malloc(sizeof(int) * n);
  return tab;
}
```

2. __desalloue_matrice__
```c
void desalloue_matrice(int **tab, int n){
  for (int i = 0; i < n; i++)
    free(tab[i]);
  free(tab);
}
```

3. __remplir_matrice__
```c
void remplir_matrice(int **tab, int n, int v){
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      tab[i][j] = (int)(rand() % v);
}
```

4. __afficher_tableau__
```c
void  afficher_tableau(int* tab,int n){
  printf("[ ");
  for(int i = 0 ; i < n ; i++)
    printf("%d ", tab[i]);
  printf(" ]");
}
```

### Question 3

En augmentant la taille du tableau on observe sur la courbe ``01_courbes_vitesse.png`` une augmentation du temps dans l'algo1 tandis que l temps de l'algo2 reste constant.
Ce qui montre l'efficacité de ``somme_carres_2``.

### __Partie 2__ : Tableau à deux dimension

### Question 5

On compare les temps de calculs des deux algorithmes en fonction de n elements dans la matrice. Pour ce faire on réitère l'expérience 2 fois afin de montrer qu'il ne s'agit pas d'une coincidence.
-	La courbe représentant le differentiel de temps de ``tous_diff1`` semble varier aléatoirement. Cela est dû au fait que l'emplacement des doublons change grandement le temps d'execution de l'algorithme. On doit alors passer n fois sur la matrice.
- Tandis que la courbe représentant le differentiel de temps de ``tous_diff2`` semble bien plus stable. Cela vient du fait que l'on a besoin de parcourir la matrice une seule fois seulement comme on stock les nombres deja rencontrés.


### Question 6

3. La complexité est meilleur car on passe de ``O(n^3)`` à ``O(n^3 - k)``. Ou k representent les calcules ignorés car multiplication par 0.
4. 
-	La courbe représentant le differentiel de temps de ``prod_matrice_1`` semble augmenter exponentiellement. En effet, plus la matrice est grande plus le nombre de calcul a faire est important.
- Tandis que la courbe représentant le differentiel de temps de ``prod_matrice_2`` semble augmenter moins rapidement. Cela est du au fait que l'on prenne en compte qu'il s'agisse du produit d'une matrice triangulaire superieur et inferieur. Ainsi on économise alors la moitié de nos calculs ce qui devient tres considerable lorsque la matrics est tres grande.
