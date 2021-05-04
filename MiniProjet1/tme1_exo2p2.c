#include "header.h"

int **alloue_matrice(int n){
  int **tab;
  
  if (!(tab = malloc(sizeof(int *) * n))){
    printf("Erreur de malloc!\n");	
		return NULL;
	}
  for (int i = 0; i < n; i++){
    if (!(tab[i] = malloc(sizeof(int) * n))){
      printf("Erreur de malloc!\n");	
		  return NULL; 
    }
  }
  return tab;
}

void desalloue_matrice(int **tab, int n){
  for (int i = 0; i < n; i++)
    free(tab[i]);
  free(tab);
}

void remplir_matrice(int **tab, int n, int v){
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      tab[i][j] = (int)(rand() % v);
}

void remplir_matrice_sup(int **tab, int n, int v){
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i > j)
        tab[i][j] = 0;
      else
        tab[i][j] = (int)(rand() % v);
}

void remplir_matrice_inf(int **tab, int n, int v){
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i < j)
        tab[i][j] = 0;
      else
      tab[i][j] = (int)(rand() % v);
}

void afficher_matrice(int **tab, int n){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++)
      printf("%d ", tab[i][j]);
    printf("\n");
  }
  printf("\n");
}