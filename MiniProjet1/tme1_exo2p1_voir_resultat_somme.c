#include "header.h"

#define TAILLE_TAB 4
#define BORNE 4

int   *alloue_tableau(int n){
    int *tab;
    
    if (!(tab = malloc(sizeof(int) * n))){
      printf("Erreur de malloc!\n");	
		  return NULL;
	  }
    return tab;
}

void  desalloue_tableau(int *tab,int n){
  free(tab);
}

void  remplir_tableau(int *tab, int n, int v){
    for(int i = 0; i < n; i++)
        tab[i]=(int)(rand() % v);//on donne une valeur aleatoire au case du tableau courant
}

void  afficher_tableau(int* tab,int n){
  printf("[ ");
  for(int i = 0 ; i < n ; i++)
    printf("%d ", tab[i]);
  printf("]\n");
}

int   somme_carres_1(int *tab, int n){
  int somme = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      somme += (tab[i]-tab[j]) * (tab[i]-tab[j]); // on effectue la formule demander dans l'exercice
  return somme;
}

int   somme_carres_2(int *tab, int n){
  int x = 0;
  int y = 0;
  for(int i = 0; i < n; i++){
    x += tab[i] * tab[i];
    y += tab[i];
  }
  return 2 * n * x - 2 * (y * y); // on  return la somme carres via la formule developper et amenager de la question precedente
}

int   main(){
  //initialisation des variables
  srand(time(NULL));
  int n = TAILLE_TAB;
  int v = BORNE;
  int *tab = alloue_tableau(n);

  printf("On remplit un tableau de taille %d avec une borne de %d\n", n, v);
  remplir_tableau(tab, n, v);
  afficher_tableau(tab,n);
  int s1 = somme_carres_1(tab, n);//on fait la somme avec l'algo 1
  int s2 = somme_carres_2(tab, n);//on fait la somme avec l'algo 2

  printf("Somme pour :\n  -  Algo 1 = %d\n  -  Algo 2 = %d\n", s1, s2);

  //libération du tableau
  free(tab);
  return 0;
}
