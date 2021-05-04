#include "header.h"

int tous_diff(int **tab, int n){
  for (int a = 0; a < n; a++)
    for (int b = 0; b < n; b++)
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          if ((a != i || b != j) && (tab[a][b] == tab[i][j]))
            return 0; //return 0 si c'est faux
  return 1;           // return 1 si c'est vrai
}

int tous_diff2(int **tab, int n, int borne){
  int *t = calloc(borne, sizeof(int));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++){
      if (t[tab[i][j]] == 1){
        free(t);
        return 0;
      }else
        t[tab[i][j]] = 1;
    }
  free(t);
  return 1;
}

void prod_matrice_1(int **tab1, int **tab2, int **tab_retour, int n){
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++){
      tab_retour[i][j] = 0;
      for (int k = 0; k < n; k++)
        tab_retour[i][j] += tab1[i][k] * tab2[k][j];
    }
}

void prod_matrice_2(int **tab1, int **tab2, int **tab_retour, int n){
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++){
      tab_retour[i][j] = 0;
      for (int k = i; k < n; k++)
        if (!(k < j))
          tab_retour[i][j] += tab1[i][k] * tab2[k][j];
    }
}

int main(){
  srand(time(NULL));
  //initialisation des variables
  int n = 2;
  int v = 100;
  //allocation des matrices
  int **tab1 = alloue_matrice(n);
  remplir_matrice(tab1, n, v);
  printf("Affichage de matrice carre avec n = %d et borne = %d\nOn obtient la matrice:\n\n", n, v);
  afficher_matrice(tab1, n);
  printf("Return de la fonction tous_diff:\n  - Algo 1 : %d\n  - Algo 2 : %d\n", tous_diff(tab1,n), tous_diff2(tab1,n,v));
  desalloue_matrice(tab1, n);

  return 0;
}
